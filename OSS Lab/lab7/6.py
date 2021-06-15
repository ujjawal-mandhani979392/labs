import pandas as pd
data = pd.read_csv("data.csv")


def average_milege():
    print("\naverage milege of each car making company")
    temp = data.groupby('company')
    temp1 = temp['company', 'average-mileage'].mean()
    print("\n")
    print(temp1)


average_milege()
