// leetcode 468
// Validate IP Address

// 给定一个IP，验证该IP是否为有效的IP，并返回对应的IP版本
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> split(string queryIP, string delim) {
        int index;
        int lastIndex = 0;
        vector<string> ans;

        while ((index = queryIP.find(delim, lastIndex)) != string::npos) {
            ans.push_back(queryIP.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();
        }

        if (lastIndex != queryIP.length()) {
            ans.push_back(queryIP.substr(lastIndex, queryIP.length() - lastIndex));
        }

        return ans;
    }

    bool validIPv4(string ip) {
        if (ip.length() > 3 || ip.length() == 0) return false;

        bool hasValidNumber = false;

        for (int i = 0; i < ip.length(); i++) {
            if (ip[i] == '0') {
                // 注意Leading zero的处理
                if (ip.length() > 1 && !hasValidNumber) return false;
                else continue;
            }
            else {
                if (ip[i] >= '0' && ip[i] <= '9') hasValidNumber = true;
                else return false;
            }
        }

        return stoi(ip) <= 255 && stoi(ip) >= 0;
    }

    set<char> hex = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F'
    };

    bool validIPv6(string ip) {
        if (ip.length() > 4 || ip.length() == 0) return false;

        for (int i = 0; i < ip.length(); i++) {
            if (hex.find(ip[i]) == hex.end()) return false;
            else continue;
        }

        return true;
    }


    string validIPAddress(string queryIP) {
        int ipVersion = 0;
        for (int i = 0; i < queryIP.length(); i++) {
            if (queryIP[i] == '.') {
                ipVersion = 4;
                break;
            }
            else if (queryIP[i] == ':') {
                ipVersion = 6;
                break;
            }
        }

        if (ipVersion == 4) {
            if (queryIP.back() == '.') return "Neither";

            vector<string> ips = split(queryIP, ".");

            if (ips.size() != 4) return "Neither";

            for (int i = 0; i < ips.size(); i++) {
                if (!validIPv4(ips[i])) return "Neither";
            }
            return "IPv4";
        }

        else if (ipVersion == 6) {
            if (queryIP.back() == ':') return "Neither";

            vector<string> ips = split(queryIP, ":");

            if (ips.size() != 8) return "Neither";

            for (int i = 0; i < ips.size(); i++) {
                if (!validIPv6(ips[i])) return "Neither";
            }
            return "IPv6";
        }

        else return "Neither";
    }
};