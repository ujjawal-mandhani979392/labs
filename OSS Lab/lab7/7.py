import pandas as pd
data = pd.read_csv("data.csv")


def merging_df():
    print("\nMerging two dataframes")
    Price = {'Company': ['Toyota', 'Honda', 'BMV', 'Audi'],
             'Price': [23845, 17995, 135925, 71400]}
    carPriceDf = pd.DataFrame.from_dict(Price)
    Horsepower = {'Company': ['Toyota', 'Honda', 'BMV',
                              'Audi'], 'horsepower': [141, 80, 182, 160]}
    carsHorsepowerDf = pd.DataFrame.from_dict(Horsepower)
    carsDf = pd.merge(carPriceDf, carsHorsepowerDf, on="Company")
    print(carsDf)


merging_df()
