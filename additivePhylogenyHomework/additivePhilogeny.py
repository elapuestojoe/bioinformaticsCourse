
import copy
import networkx as nx 
import matplotlib.pyplot as plt
import pandas as pd
# keys = ["i", "j", "k", "l"]
keys = ["Cow", "Pig", "Horse", "Mouse", "Dog", "Cat", "Turkey", "Civet", "Human"]

def findAttachmentPoint(baldMatrix, j):
    for i in range(j):
        for k in range(j):
                if(baldMatrix[j][i] + baldMatrix[j][k] == baldMatrix[i][k] and i!=k):
                    print(baldMatrix[i][k])
                    return i, j, k
    return -1, -1, -1

def reduceMatrix(distanceMatrix, index, limbLength):
    for i in range(index):
        distanceMatrix[i][index] -= limbLength
        distanceMatrix[index][i] -= limbLength
        if(distanceMatrix[i][index] <0):
            distanceMatrix[i][index] *= -1
        if(distanceMatrix[index][i] < 0):
            distanceMatrix[index][i] *= -1
    return distanceMatrix

def calculateLimbLength(distanceMatrix, index):
    minVal = None
    for i in range(0, index):
        for j in range(i+1, index):
            val = (distanceMatrix[index][i] + distanceMatrix[index][j] - distanceMatrix[j][i]) / 2
            if(minVal is None or  val < minVal):
                minVal = val
    return minVal

def calculateAdditivePhylogeny(distanceMatrix, index, graph):

    if(index == 1):
        return

    limbLength = calculateLimbLength(distanceMatrix, index)
    
    baldMatrix = reduceMatrix(copy.deepcopy(distanceMatrix), index, limbLength)

    calculateAdditivePhylogeny(distanceMatrix, index-1, graph)
    nodes = len(graph)
    graph[nodes] = {}

    for i in range(index):
        for k in range(index):
            if(i!=index and k != index):
                if(baldMatrix[index][i] + baldMatrix[index][k] == baldMatrix[i][k]):
                    graph[keys[i]][nodes] = baldMatrix[index][i]

    print("Index {} - {}".format(index, keys[index]))
    print(graph)
    for row in baldMatrix:
        print(row)


    graph[nodes][keys[index]] = limbLength
    graph[keys[index]][nodes] = limbLength


    print("Index {} Limb length: {}".format(index, limbLength))

def pruneGraph(graph):
    for key in graph:
        minIndex = None
        minVal = None
        for index in graph[key]:
            if(minIndex is None):
                minIndex = index
                minVal = graph[key][index]
            if(minVal > graph[key][index]):
                minIndex = index
                minVal = graph[key][index]
        graph[key] = {minIndex: minVal}

def main():

    # distanceMatrix = [
    #     [0, 13, 21, 22],
    #     [13, 0, 12, 13],
    #     [21, 12, 0, 13],
    #     [22, 13, 13, 0]
    # ]

    distanceMatrix = pd.read_csv("SARS.csv", index_col=0, header=0).values
    print(distanceMatrix)

    graph = {}
    for i in range(len(distanceMatrix)):
        graph[keys[i]] = {}

    calculateAdditivePhylogeny(distanceMatrix, len(distanceMatrix) - 1, graph)
    pruneGraph(graph)

    print(graph)

if __name__ == "__main__":
    main()