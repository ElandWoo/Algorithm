class Solution {
public:
	/*
	Create a fitler ,if address[i] is the target , change it .
	O(1)
	*/
    string defangIPaddr(string address) {
        // the size of address is changing with the loop
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
                i += 2; // cause "[.]" is two longer than '.'
            }
        }
        return address;
    }
}
