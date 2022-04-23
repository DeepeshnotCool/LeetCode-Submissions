class Solution {
public:
    map<int, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[m.size()] = longUrl;
        //cout<<"http://tinyurl.com/"<<to_string(m.size()-1);
        return "http://tinyurl.com/"+to_string(m.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = shortUrl.rfind('/');
        return m[stoi(shortUrl.substr(i+1))];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));