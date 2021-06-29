class trie:
    key: str
    child: dict
    def __init__(self, key):
        self.child = dict()
        self.key = key

    def print(self, depth=-1):
        if self.key != None:
            print('--' * depth + self.key)
        for c in sorted(self.child):
            self.child[c].print(depth+1)

    def add(self, keys):
        if len(keys) == 0: return
        key = keys[0]
        if key in self.child:
            self.child[key].add(keys[1:])
        else:
            self.child[key] = trie(keys[0])
            self.child[key].add(keys[1:])

N = int(input())
root = trie(None)
for i in range(N):
    arr = input().split()[1:]
    root.add(arr)
root.print()