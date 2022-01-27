import requests


FILENAME = "rqsts.in.txt"

with open(FILENAME, 'r') as f:
    url = f.readline().strip()

data = requests.get(url).text
print(len(data.splitlines()))
