import pandas as pd
data = pd.read_csv("data.csv")


def all_bmw_cars():
    print("\nAll BMW cars")
    print(data.loc[data['company'] == 'volvo'])


all_bmw_cars()
