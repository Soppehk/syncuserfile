def solo_maiuscole(t):
    res = []
    for s in t:
        if s.isupper():
            res.append(s)
    return res

t = ["CIAO", "mona", "boltolin"]
print(solo_maiuscole(t))
