#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Coord {
    int r, c;
    bool operator<(const Coord& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
    bool operator==(const Coord& other) const {
        return r == other.r && c == other.c;
    }
};

struct Monster {
    string name;
    int w, a, h_max, h_cur, e;
    bool is_boss;
};

struct Item {
    char type; 
    string s_val;
    int n_val; 
};

struct Player {
    int r, c;
    int start_r, start_c;
    int max_hp, cur_hp;
    int base_att, base_def;
    int wep_att, armor_def;
    int level, cur_exp, need_exp;
    set<string> accessories;

    int get_total_att() { return base_att + wep_att; }
    int get_total_def() { return base_def + armor_def; }
    
    bool has_acc(string name) {
        return accessories.count(name);
    }
};

int R, C;
vector<string> grid;
string commands;
map<Coord, Monster> monsters;
map<Coord, Item> items;
Player player;
int passed_turns = 0;
string kill_reason = "";
bool game_cleared = false;
bool player_dead = false;

void init_game() {
    player.max_hp = 20;
    player.cur_hp = 20;
    player.base_att = 2;
    player.base_def = 2;
    player.wep_att = 0;
    player.armor_def = 0;
    player.level = 1;
    player.cur_exp = 0;
    player.need_exp = 5;
}

void check_levelup() {
    if (player.cur_exp >= player.need_exp) {
        player.level++;
        player.max_hp += 5;
        player.base_att += 2;
        player.base_def += 2;
        player.cur_hp = player.max_hp;
        player.cur_exp = 0; 
        player.need_exp = 5 * player.level;
    }
}

bool try_revive() {
    if (player.has_acc("RE")) {
        player.accessories.erase("RE");
        player.cur_hp = player.max_hp;
        player.r = player.start_r;
        player.c = player.start_c;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    grid.resize(R);
    init_game();

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '@') {
                player.r = i;
                player.c = j;
                player.start_r = i;
                player.start_c = j;
                grid[i][j] = '.'; 
            }
        }
    }

    cin >> commands;

    int K, L;
    int monster_cnt = 0;
    int item_cnt = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(grid[i][j] == '&' || grid[i][j] == 'M') monster_cnt++;
            if(grid[i][j] == 'B') item_cnt++;
        }
    }

    for (int i = 0; i < monster_cnt; i++) {
        int r, c, w, a, h, e;
        string s;
        cin >> r >> c >> s >> w >> a >> h >> e;
        r--; c--;
        Monster m = {s, w, a, h, h, e, false};
        if (grid[r][c] == 'M') m.is_boss = true;
        monsters[{r, c}] = m;
    }

    for (int i = 0; i < item_cnt; i++) {
        int r, c;
        char t;
        string s_val; 
        int n_val = 0;
        cin >> r >> c >> t;
        r--; c--;
        
        if (t == 'O') {
            cin >> s_val;
        } else {
            cin >> n_val;
        }
        items[{r, c}] = {t, s_val, n_val};
    }

    for (char cmd : commands) {
        passed_turns++;

        int nr = player.r;
        int nc = player.c;

        if (cmd == 'L') nc--;
        else if (cmd == 'R') nc++;
        else if (cmd == 'U') nr--;
        else if (cmd == 'D') nr++;

        if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') {
            nr = player.r;
            nc = player.c;
        }

        player.r = nr;
        player.c = nc;

        char cell = grid[nr][nc];

        if (cell == 'B') {
            Item& it = items[{nr, nc}];
            if (it.type == 'W') {
                player.wep_att = it.n_val;
            } else if (it.type == 'A') {
                player.armor_def = it.n_val;
            } else if (it.type == 'O') {
                if (player.accessories.size() < 4 && !player.has_acc(it.s_val)) {
                    player.accessories.insert(it.s_val);
                }
            }
            grid[nr][nc] = '.'; 
        } 
        else if (cell == '^') {
            int dmg = 5;
            if (player.has_acc("DX")) dmg = 1;
            
            player.cur_hp -= dmg;
            if (player.cur_hp <= 0) {
                if (try_revive()) {
                } else {
                    player_dead = true;
                    kill_reason = "SPIKE TRAP";
                    break;
                }
            }
        }
        else if (cell == '&' || cell == 'M') {
            Monster& mon = monsters[{nr, nc}];

            if (mon.is_boss && player.has_acc("HU")) {
                player.cur_hp = player.max_hp;
            }

            bool first_attack = true;
            bool win = false;

            while (true) {
                int p_att = player.get_total_att();
                
                if (first_attack && player.has_acc("CO")) {
                    if (player.has_acc("DX")) p_att *= 3;
                    else p_att *= 2;
                }

                int p_dmg = max(1, p_att - mon.a);
                mon.h_cur -= p_dmg;

                if (mon.h_cur <= 0) {
                    win = true;
                    break;
                }

                int m_dmg = max(1, mon.w - player.get_total_def());
                
                if (first_attack && mon.is_boss && player.has_acc("HU")) {
                    m_dmg = 0;
                }

                player.cur_hp -= m_dmg;

                if (player.cur_hp <= 0) {
                    win = false;
                    break;
                }

                first_attack = false;
            }

            if (win) {
                int exp_gain = mon.e;
                if (player.has_acc("EX")) {
                    exp_gain = (int)(exp_gain * 1.2);
                }
                player.cur_exp += exp_gain;
                check_levelup();

                if (player.has_acc("HR")) {
                    player.cur_hp = min(player.max_hp, player.cur_hp + 3);
                }

                if (mon.is_boss) {
                    game_cleared = true;
                    grid[nr][nc] = '.'; 
                    break;
                } else {
                    grid[nr][nc] = '.'; 
                }
            } else {
                if (try_revive()) {
                    mon.h_cur = mon.h_max;
                } else {
                    player_dead = true;
                    kill_reason = mon.name;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!player_dead && i == player.r && j == player.c) {
                cout << '@';
            } else {
                cout << grid[i][j];
            }
        }
        cout << "\n";
    }

    cout << "Passed Turns : " << passed_turns << "\n";
    cout << "LV : " << player.level << "\n";
    cout << "HP : " << (player.cur_hp < 0 ? 0 : player.cur_hp) << "/" << player.max_hp << "\n";
    cout << "ATT : " << player.base_att << "+" << player.wep_att << "\n";
    cout << "DEF : " << player.base_def << "+" << player.armor_def << "\n";
    cout << "EXP : " << player.cur_exp << "/" << player.need_exp << "\n";

    if (game_cleared) {
        cout << "YOU WIN!" << "\n";
    } else if (player_dead) {
        cout << "YOU HAVE BEEN KILLED BY " << kill_reason << ".." << "\n";
    } else {
        cout << "Press any key to continue." << "\n";
    }

    return 0;
}