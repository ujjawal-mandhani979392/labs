import pandas as pd
data = pd.read_csv("data.csv")


def Head_and_tail():
    print("Head\n")
    print(data.head())
    print("Tail")
    print(data.tail())


Head_and_tail()
