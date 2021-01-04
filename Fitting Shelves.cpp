
// We want to maximise our large shelves and minimise our empty space. So we:
// 1) Find maximum count of large shelves we can afford.
// 2) Try to check iteratively how much space is remaining when we use Maximum Count of large shelves, 
// Maximum Count of large shelves - 1, Maximum Count of large shelves - 2, e.t.c.
// 3) We iteratively try each count of large shelves, calculate how many shelves we can afford 
// with the free space and how much space left In total when we use current count of large shelves 
// and small shelves and just choose the minimum one with the largest amount of large shelves.

// Greedy Solution - O(N) Time Complexity, O(1) Space Complexity
void FitShelves(int w, int m, int n) {
    int small = 0, large = 0, space = INF;
    int maxLarge = w / n;
    for (int currentLarge = maxLarge; currentLarge >= 0; --currentLarge) {
        int currentSmall = (w - currentLarge * n) / m;
        int currentSpace = w - currentSmall * m - currentLarge * n;
        if (currentSpace == space and currentLarge > large) {
            large = currentLarge;
            small = currentSmall;
        }
        else if (currentSpace < space) {
            space = currentSpace;
            large = currentLarge;
            small = currentSmall;
        }
    }
    cout << small << ' ' << large << ' ' << space << '\n';
}
