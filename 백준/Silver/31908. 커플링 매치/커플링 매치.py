import sys
class person():
    
    def __init__(self,name,features):
        self.name=name
        if(features!=['-']):
            self.features=set(features)
            self.addFeatureSet(features)
        else:
            self.features=set()
            
    def addFeatureSet(self,feature_list):
        global features_dict
        for item in feature_list:
            if (item in features_dict):
                features_dict[item].add(self.name)
            else:
                features_dict[item]=set([self.name])

n=int(input())
features_dict=dict()
people_dict=dict()
people_set=set()
for _ in range(n):
    name,features=sys.stdin.readline().split()
    people_dict[name]=person(name, features.split('_'))
    people_set.add(name)

people_total_set=people_set.copy()
result=[]
while people_set:
    person1=people_dict[people_set.pop()]
    intersection_result=set()
    if(person1.features):
        intersection_result=people_total_set.copy()
    for feat in person1.features:
        intersection_result.intersection_update(features_dict[feat])
    if(len(intersection_result)==2):
        tmp=[]
        for name in intersection_result:
            tmp.append(name)
            people_set.discard(name)
        result.append(tmp)
    else:
        for name in intersection_result:
            people_set.discard(name)
if(len(result)):
    sys.stdout.write(f'{len(result)}\n')
    for _ in range(len(result)):
        sys.stdout.write(f'{" ".join(result.pop())}\n')
else:
    sys.stdout.write(f'0')