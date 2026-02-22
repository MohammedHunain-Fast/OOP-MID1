#include <iostream>
#include <string>
using namespace std;

class User {
    string name, about, phone_no;
public:
    User() : name(" "), about(" "), phone_no(" ") {}
    User(string name, string phone_no) : name(name), phone_no(phone_no), about("Available") {}
    
    void setabout(string about) { this->about = about; }
    string getname() { return name; }
    void getdetails() {
        cout << "Name: " << name << "\nAbout: " << about << "\nPhone: " << phone_no << endl;
    }
};

class Message {
    string sender_name, text, timestamp;
public:
    Message() : sender_name(" "), text(" "), timestamp("") {}
    void setdetails(string s, string t, string time) {
        sender_name = s; text = t; timestamp = time;
    }
    void getdetails() {
        cout << "[" << timestamp << "] " << sender_name << ": " << text << endl;
    }
};

class WhatsAppGroup {
    int message_count, max_messages;
    int admin_count, max_admin;
    int member_count; // Tracks current members
    string group_info, group_name, creation_date;
    User* admin_list[5];
    User* member_list[20]; // Changed to 20 as per prompt
    Message *messages;

public:
    // 1. Parameterized Constructor
    WhatsAppGroup(string info, string name, string date, int max_m) 
        : group_info(info), group_name(name), creation_date(date), 
          max_messages(max_m), message_count(0), max_admin(5), admin_count(0), member_count(0) { // Initialized member_count
        messages = new Message[max_messages];
    }

    // 2. Deep Copy Constructor
    WhatsAppGroup(const WhatsAppGroup& w) {
        group_info = w.group_info;
        group_name = w.group_name;
        creation_date = w.creation_date;
        max_messages = w.max_messages;
        message_count = w.message_count;
        admin_count = w.admin_count;
        member_count = w.member_count;

        messages = new Message[max_messages];
        for (int i = 0; i < message_count; i++) messages[i] = w.messages[i];
        for (int i = 0; i < admin_count; i++) admin_list[i] = w.admin_list[i];
        for (int i = 0; i < member_count; i++) member_list[i] = w.member_list[i];
    }

    // 3. Destructor
    ~WhatsAppGroup() {
        delete[] messages;
    }

    // Needed to satisfy the requirement: "Admin must be an existing member"
    void addMember(User* u) {
        if (member_count < 20) {
            member_list[member_count++] = u;
        }
    }

    void addAdmin(User* u) {
        // Validation: Is this user actually in the member_list?
        bool isMember = false;
        for (int i = 0; i < member_count; i++) {
            if (member_list[i] == u) {
                isMember = true;
                break;
            }
        }

        if (!isMember) {
            cout << "Error: User must be a member before becoming Admin!\n";
            return;
        }

        if (admin_count < max_admin) {
            admin_list[admin_count++] = u;
        } else {
            cout << "Max admins reached!\n";
        }
    }

    void removeAdmin(User* u) {
        if (admin_count <= 1) { // Rule: Must have at least one admin
            cout << "Access denied: There must be at least one admin!\n";
            return;
        }
        for (int i = 0; i < admin_count; i++) {
            if (admin_list[i] == u) {
                for (int j = i; j < admin_count - 1; j++) {
                    admin_list[j] = admin_list[j + 1];
                }
                admin_count--;
                return;
            }
        }
    }

    void sendmessage(string sender, string text, string timestamp) {
        if (message_count < max_messages) {
            messages[message_count++].setdetails(sender, text, timestamp);
        } else {
            // Optional: for "only the last 10 messages", you'd shift the array here
            for (int i = 0; i < max_messages - 1; i++) messages[i] = messages[i+1];
            messages[max_messages - 1].setdetails(sender, text, timestamp);
        }
    }
};
