class Rectangle {
    private:
        int width, height;
    public:
        Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
        }
        int get_width() const {return width;
        }
        int get_height() const {return height;
        }
        void set_width(int width) {if(width > 0 && width <= 1000)
            this->width = width;
        }
        void set_height(int height) {if(height > 0 && height <= 2000)
            this->height = height;
        }
        int area() const {return this->width * this->height;
        }
        int perimeter() const {return 2 * (this->width + this->height);
        }
        bool is_square() const {if (this -> width == this -> height) return true;
        else return false;
        }
};
