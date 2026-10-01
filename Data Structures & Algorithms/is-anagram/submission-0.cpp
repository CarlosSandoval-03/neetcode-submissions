class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> hmap;
        
        // Conteo de caracteres
        for (const char& c : s) {
            if (hmap.find(c) != hmap.end())
                hmap[c] += 1;
            else
                hmap[c] = 1;
        }

        // Se resta cada incidencia, map final con todos los elementos igual a 0
        for (const char& c : t) {
            if (hmap.find(c) != hmap.end())
                hmap[c] -= 1;
            else
                return false; // No encontrado
        }

        for (const auto& [_, v] : hmap) {
            if (v != 0)
                return false;
        }

        return true;
    }
};
