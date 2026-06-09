class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
    
    // यदि कोई व्यक्ति बैठाना ही नहीं है, तो हमेशा true होगा
    if (k <= 0) return true;

    for (int i = 0; i < n; i++) {
        // चेक करें कि क्या वर्तमान सीट खाली है
        if (seats[i] == 0) {
            // बाईं ओर की स्थिति चेक करें (यदि पहला एलिमेंट है तो बाईं ओर खाली मानेंगे)
            bool isLeftEmpty = (i == 0 || seats[i - 1] == 0);
            
            // दाईं ओर की स्थिति चेक करें (यदि आखिरी एलिमेंट है तो दाईं ओर खाली मानेंगे)
            bool isRightEmpty = (i == n - 1 || seats[i + 1] == 0);

            // यदि दोनों तरफ खाली है, तो यहाँ व्यक्ति को बैठा दें
            if (isLeftEmpty && isRightEmpty) {
                seats[i] = 1; // सीट भर गई
                k--;         // एक व्यक्ति कम हुआ
                
                // यदि सभी लोग बैठ चुके हैं, तो आगे चेक करने की ज़रूरत नहीं है
                if (k == 0) {
                    return true;
                }
            }
        }
    }

    // यदि लूप खत्म होने के बाद भी k > 0 है, तो सबको बैठाना संभव नहीं था
    return k <= 0;
    }
};