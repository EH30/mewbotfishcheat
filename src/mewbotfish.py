import json

class FishCheat:
    def __init__(self):
        self.jdata = None 
        with open("poke_names.json", "r") as opn:
            self.jdata = json.load(opn)
        opn.close()

    def get_pos(self, userin, pos):
        for i in range(len(userin)):
            if userin[i].isalpha():
                pos.append(i)
        
        return pos

    def match_name(self, name, match, pos):
        for x in pos:
            if name[x] == match[x]:
                continue
            else:
                return 1
        return 0
    
    def run_search(self, user_input):
        out = []
        pos = self.get_pos(user_input, [])
        temp = None
        for line in self.jdata[str(len(user_input))]:
            temp = self.match_name(line.lower(), user_input.lower(), pos)
            if temp == 0:
                out.append(line.lower())
        
        return out
