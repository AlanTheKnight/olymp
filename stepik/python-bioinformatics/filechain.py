import requests


FILENAME = "filechain.in.txt"
BASE_URL = "https://stepic.org/media/attachments/course67/3.6.3/"


with open(FILENAME, 'r') as f:
    url = f.readline().strip()


data = requests.get(url).text
while not data.startswith("We"):
    data = requests.get(BASE_URL + data).text
    print("New location:", data)
with open("filechain.out.txt", 'w') as f:
        f.write(data)
