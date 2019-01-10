import json
import string
import random

startPoint = "A"
result = {
    "vertices": [startPoint],
    "edges": []
}

def idGenerator(size=8, chars=string.ascii_uppercase):
    return ''.join(random.choice(chars) for _ in range(size))

def connectPoints(first, second):
    return {"firstVertex": first, "secondVertex": second}

def crateStar(number, middleNode, idLength=8, idChars=string.ascii_uppercase):
    newNodes = [idGenerator(idLength, idChars) for i in range(number)]
    newVertices = [connectPoints(node, middleNode) for node in newNodes]

    result['vertices'].extend(newNodes)
    result['edges'].extend(newVertices)

    return newNodes

def createLine(number, startPoint, idLength=8, idChars=string.ascii_uppercase):
    if number < 2:
        return []

    newNodes = [idGenerator(idLength, idChars) for i in range(number)]
    newVertices = [connectPoints(newNodes[n1], newNodes[n1 + 1]) for n1 in range(len(newNodes) - 1)]
    newVertices.append(connectPoints(startPoint, newNodes[0]))

    result['vertices'].extend(newNodes)
    result['edges'].extend(newVertices)

    return newNodes

def createFullyConnected(number, startPoint, idLength=8, idChars=string.ascii_uppercase):
    if number == 0:
        return []

    newNodes = [idGenerator(idLength, idChars) for i in range(number)]
    newVertices = [connectPoints(newNodes[n1], newNodes[n2]) for n1 in range(len(newNodes)) for n2 in range(n1+1,len(newNodes))]
    newVertices.append(connectPoints(newNodes[0], startPoint))

    result['vertices'].extend(newNodes)
    result['edges'].extend(newVertices)

    return newNodes

def addRandomBridges(graph, number, idLength=8, idChars=string.ascii_uppercase):
    newNodes = [idGenerator(idLength, idChars) for i in range(number)]
    newVertices = [connectPoints(node, random.choice(graph)) for node in newNodes]

    result['vertices'].extend(newNodes)
    result['edges'].extend(newVertices)

    return newNodes


star1 = createLine(2000, startPoint)
addRandomBridges(star1, 10, 4)

file = open('../input/test2.json', 'w')
file.write(json.dumps(result))
file.close()