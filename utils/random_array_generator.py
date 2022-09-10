import random
import pdb
import argparse
import os
import math
import numpy as np
from scipy import sparse

parser = argparse.ArgumentParser(description='Input Matrix generator')
parser.add_argument('--seed', type=int, default=0, help='Seed Value')
parser.add_argument('--n', type=int, default=3, help='Array order')
parser.add_argument('--l', type=int, default=3, help='Array len')
parser.add_argument('--sparsity', type=int, default=0, help='Sparisty of matrix in %')
parser.add_argument('--dump', type=str, default='input_matrix.in', help='File name')

def createRandomMatrix(n,maxVal):
    # maxVal = 1000  # I don't want to get Java / C++ into trouble
    matrix= []
    for i in range(n):
      value = random.randint(1,maxVal)
      matrix.append(value)
    return matrix

def saveMatrix(matrixA, matrixB, filename):
    if os.path.exists(filename): 
        os.remove(filename)
    else:   
        print("New file created: ",filename)
    f = open(filename, "w")
    for month in (matrixA):
        f.write("\t")
        f.write(str(month))
    f.write("\n")
    for month in (matrixB):
        f.write("\t")
        f.write(str(month))
    f.write("\n")

def saveMatrixsingle(matrixA, filename):
    if os.path.exists(filename): 
        os.remove(filename)
    else:   
        print("New file created: ",filename)
    f = open(filename, "w")
    for month in (matrixA):
        f.write("\t")
        f.write(str(month))
    f.write("\n")

def saveCSRMatrix(CSR_matrix, filename):
    if os.path.exists(filename): 
        os.remove(filename)
    else:   
        print("New file created: ",filename)

    f = open(filename,"w")
    f.write(str(args.n))
    f.write("\n")
    for row, col in zip(*CSR_matrix.nonzero()):
        val = CSR_matrix[row,col]
        f.write("Row: "+str(row)+", Col: ")
        f.write(str(col)+", ")
        f.write("Val: "+str(val)+".")
        f.write("\n")
    f.close()

def main():
    global args
    args = parser.parse_args()
    print(40*"="+"\nArgs:{}\n".format(args)+40*"=")
    random.seed(args.seed)
    n = args.n
    outpath = args.dump
    maxVal = 100
    #Create dense matrix
    matrixA = createRandomMatrix(n,100)
    matrixB = createRandomMatrix(int(n/2),n-2)
    #print(matrixA)
    #Convert to sparse matrix by replacing value below threshold to 0
    if (args.sparsity):
        # print(matrixA,matrixB)
        matrixA_csr = sparse.csr_matrix(matrixA)
        #print(matrixA_csr)
        matrixB_csr = sparse.csr_matrix(matrixB)
        csr_Amatrix = "csrA_"+args.dump
        csr_Bmatrix = "csrB_"+args.dump
        saveCSRMatrix(matrixA_csr, csr_Amatrix)
        saveCSRMatrix(matrixB_csr, csr_Bmatrix)
        #print(matrixA)
    saveMatrix(matrixA, matrixB, args.dump)

if __name__ == '__main__':
    main()
