import os
import pandas as pd

os.system('cls')
l = ['jay', 'anand', 'nitin', 'rakshit',  'abhishek', 'adarsh kumar',"satyam verma", 'ansh', 'anuj goyal', 'anuj gupta', 'arpit', 'ashad', 'ayush', 'dikshit', 'gaurav', 'gautam', 'hardik', 'harsh', 'lakshya', 'prateek', 'priyanshu', 'rajat',
     'shashank', 'sachin', 'sankalp', 'satyarth', 'shagufta', 'shivam rastogi', 'shivam sharma', 'shubham', 'silky', 'sparsh', 'srishti', 'shubham kumar jha', 'sumit', 'tanmay', 'ujjwal', 'yash', 'yuvraj', 'geetanjali', 'divyansh']
path = '1.csv'


data = pd.read_csv(path)

data = data.Name ;
check  = True ;



for name in l :
    check=True
    for nam in data :
        if name.lower() in nam.lower() :
            check=False
            break
    if check :
        print(name)


not_get = ['nitin', 'jay', 'rajat', 'dikshit', 'geetanjali',
           'yash', 'rakshit', 'anuj gupta  ', 'sumit', 'satyarth']


# I = 1
# data = pd.read_csv('clas.txt')
# # print(data)
# ls = list(data.NAME)
# for name in l:
#     check = True
#     for nam in ls:
#         if name.lower() in nam.lower():
#             check = False
#             break
#     if check:
#         for nam in not_get:

#             if name.lower() in nam.lower():
#                 check = False
#                 break

#     if check :
#         print(I , name)
#         I+=1
