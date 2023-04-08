import re

mask1 = "?*a?*.*c*d*"
mask2 = "d*b?*.*?a*"


re_1 = r"..*a..*\..*c.*d.*"
re_2 = r"d.*b..*\..*.a.*"

filenames = {
    "a": "dccbab.aadc",
    "b": "dbcbbac.addcd",
    "c": "dcdba.acdb",
    "d": "dcaab.aaccd",
    "e": "ddbab.cadd",
    "f": "dbbac.dcaad",
}


for key, filename in filenames.items():
    if re.fullmatch(re_1, filename) and re.fullmatch(re_2, filename):
        print(key, filename)
