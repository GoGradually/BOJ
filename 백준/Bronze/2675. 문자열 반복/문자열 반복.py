numCase = int(input())
resultString = ""

for i in range(numCase):
    numRepeats, textString = input().split()
    numRepeats = int(numRepeats)
    for j in range(len(textString)):
        resultString += textString[j] * numRepeats
    print(resultString)
    resultString = ""
