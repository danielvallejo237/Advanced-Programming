import numpy as np 
import random 

with open('case.txt','w') as file:
    test_cases=random.randint(1,15)
    file.write(str(test_cases)+'\n')
    for case in range(test_cases):
        fuerza=random.randint(1,50)
        poblaciones=random.randint(1,20000)
        file.write(str(fuerza)+'\n')
        file.write(str(poblaciones)+'\n')
        for poblacion in range(poblaciones):
            x=random.randint(0,1024)
            y=random.randint(0,1024)
            size=random.randint(1,255)
            file.write(str(x)+" "+str(y)+" "+str(size)+"\n")
