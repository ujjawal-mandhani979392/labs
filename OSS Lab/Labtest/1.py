import pandas as pd
diamonds = pd.read_csv(
    'https://raw.githubusercontent.com/mwaskom/seaborn-data/master/diamonds.csv')
print("Original Dataframe:")
print(diamonds.head())
print("\nSeries sorted by its values:")
print(diamonds.cut.value_counts().sort_values())
print("\nSeries sorted by its index:")
print(diamonds.cut.value_counts().sort_index())
diamonds["new_col"] = diamonds["price"] * diamonds["carat"]
diamonds.sort_values(by='new_col')
print(diamonds.head())
