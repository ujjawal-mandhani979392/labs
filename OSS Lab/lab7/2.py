import pandas as pd
data = pd.read_csv("data.csv")


def replace_with_nan():
    print("\nReplace all column values which contain ‘?’ and ‘n.a.’ with NaN")
    data.replace(to_replace=["?", "na"], value="NaN")
    data.to_csv("data.csv")


replace_with_nan()
