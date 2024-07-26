class TrieNode:
    def __init__(self, value):
        self.v = value
        self.children = {}
    def insert(self, number, bit):
        if bit < 0:
            self.children['T'] = TrieNode('T')
            return
        current_bit = (number >> bit) & 1
        if current_bit not in self.children:
            self.children[current_bit] = TrieNode(current_bit)
        self.children[current_bit].insert(number,bit-1)
    def remove(self, number, bit):
        if bit < 0:
            del self.children['T']
            return len(self.children) == 0
        current_bit = (number >> bit) & 1
        result = self.children[current_bit].remove(number,bit-1)
        if result:
            del self.children[current_bit]
        return len(self.children) == 0