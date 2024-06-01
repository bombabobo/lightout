#!/bin/env python3
import sys
import math
import copy

def help():
    print("USAGE\n    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n\nDESCRIPTION")
    print("    x   abscissa of the original point\n    y   ordinate of the original point")
    print("    transfo arg1 [arg2]\n    -t i j  translation along vector (i, j)")
    print("    -z m n  scaling by factors m (x-axis) and n (y-axis)")
    print("    -r d    rotation centered in O by a d degree angle")
    print("    -s d    reflection over the axis passing through O with an inclination\n\t    angle of d degrees")
    return 0

def inverse(x):
    return abs(int(x) - 1)
def invcroix(tab, i, j):
    tab[i][j] = inverse(tab[i][j])
    if i + 1 < 5:
        tab[i + 1][j] = inverse(tab[i + 1][j])
    if i - 1 >= 0:
        tab[i - 1][j] = inverse(tab[i - 1][j])
    if j + 1 < 5:
        tab[i][j + 1] = inverse(tab[i][j + 1])
    if j - 1 >= 0:
        tab[i][j - 1] = inverse(tab[i][j - 1])
    return tab

def lightout():
    tab = [[0 for i in range(5)] for i in range(5)]
    for i in range(0, 5):
        for j in range(0, 5):
            tab[i][j] = int(sys.argv[i + 1][j])
    rettab = [[0 for i in range(5)] for i in range(5)]
    for i in range(0, 4):
        for j in range(0, 5):
            if (tab[i][j] == 1):
                rettab[i + 1][j] = inverse(rettab[i + 1][j])
                tab = invcroix(tab, i + 1, j)
    if "".join(map(str, tab[4])) == "10110":
        tab = [[0,0,0,0,1],[0,0,0,1,1],[0,0,1,0,1],[0,1,1,1,0],[1,0,0,0,0]]
        for i in range(0, 5):
            for j in range(0, 5):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "01101":
        tab = [[0,0,0,0,1],[0,0,0,1,1],[0,0,1,0,1],[0,1,1,1,0],[1,0,0,0,0]]
        for i in range(0, 5):
            for j in range(4, 0, -1):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "11100":
        tab = [[0,1,0,0,0],[1,1,1,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,1,0]]
        for i in range(0, 5):
            for j in range(0, 5):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "00111":
        tab = [[0,1,0,0,0],[1,1,1,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,1,0]]
        for i in range(0, 5):
            for j in range(4, 0, -1):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "11011":
        tab = [[0,0,1,0,0],[0,1,1,1,0],[1,0,0,0,1],[1,0,1,0,1],[0,0,1,0,0]]
        for i in range(0, 5):
            for j in range(0, 5):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "10001":
        tab = [[1,0,1,1,0],[1,0,0,0,1],[0,1,1,0,1],[0,0,0,0,0],[0,1,1,0,1]]
        for i in range(0, 5):
            for j in range(0, 5):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    elif "".join(map(str, tab[4])) == "01010":
        tab = [[1,1,1,0,0],[0,1,0,1,0],[0,0,1,1,1],[0,0,0,0,0],[0,0,1,1,1]]
        for i in range(0, 5):
            for j in range(0, 5):
                if (tab[i][j] == 1):
                    rettab[i][j] = inverse(rettab[i][j])
    for row in rettab:
        print(*row)
lightout()