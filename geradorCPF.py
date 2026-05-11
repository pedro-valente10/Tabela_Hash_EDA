# -*- coding: utf-8 -*-
"""
Created on Mon May 11 14:05:23 2026

@author: c2510382
"""
import random

def geraCPF(qtd):
    cpf=""
    file = open("C:/Users/c2510382/Documents/cpfs.txt","w")
    file.write("")
    file.close()
    file = open("C:/Users/c2510382/Documents/cpfs.txt","a")
    for j in range(qtd):
        for i in range(0,11):
            cpf = cpf + str(random.randint(0, 9))
        file.write(cpf+"\n")
        cpf = ""
    file.close()
geraCPF(100)
    