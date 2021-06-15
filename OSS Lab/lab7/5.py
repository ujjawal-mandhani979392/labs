import pandas as pd
data = pd.read_csv("data.csv")


def Highest_price_car():
    print("\nHigest price car companies")
    group1 = data.groupby('company')
    max1 = group1.max()
    max2 = max1.reset_index()
    print(max2.filter(['company', 'price']))


Highest_price_car()
