class Solution {
public:

    string encode(vector<string>& strs) {
      string encoded = "";
    for (const string& s : strs) {
        encoded += to_string(s.size()) + "#" + s;
    }
    return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
    int i = 0;
    while (i < s.size()) {
        int j = i;
        // Find the position of the '#'
        while (s[j] != '#') j++;
        int length = stoi(s.substr(i, j - i));
        j++; // move past '#'
        result.push_back(s.substr(j, length));
        i = j + length;
    }
    return result;
    }
};
