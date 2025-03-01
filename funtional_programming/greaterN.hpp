class GreaterN {
  public:
    // EFFECTS: Creates a GreaterN with the given threshold
    GreaterN(int threshold_in) : threshold(threshold_in) {}

    // EFFECTS: Returns whether or not a given value is greater than this
    // GreaterN's threshold
    bool operator()(int x) const {
        return x > threshold;
    }

  private:
    int threshold;
};