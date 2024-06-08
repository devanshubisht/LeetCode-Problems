class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();

        if (handSize % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        map<int, int> cardCount;
        for (int i = 0; i < handSize; i++) {
            cardCount[hand[i]]++;
        }

        // Process the cards until the map is empty
        while (!cardCount.empty()) {
            // Get the smallest card value
            int currentCard = cardCount.begin()->first;
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (cardCount[currentCard + i] == 0) {
                    return false;
                }
                cardCount[currentCard + i]--;
                if (cardCount[currentCard + i] < 1) {
                    // Remove the card value if its occurrences are exhausted
                    cardCount.erase(currentCard + i);
                }
            }
        }

        return true;
    }
};