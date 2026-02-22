#include <iostream>
#include <string>
using namespace std;

class User; // Forward declaration

class Comment {
    string text;
    User* author; 

public:
    Comment(string t, User* a) : text(t), author(a) {}
    
    void display() {
        // We will implement a getName() helper in User
        cout << "    - " << text << endl; 
    }
};

class Post {
    string content;
    User* creator;
    Comment** comments; // Array of pointers to Comments
    int commentCount;
    int maxComments;

public:
    Post(string text, User* u) : content(text), creator(u), commentCount(0), maxComments(5) {
        comments = new Comment*[maxComments]; // Space for 5 comments
    }

    void addComment(string text, User* commenter) {
        if (commentCount < maxComments) {
            comments[commentCount] = new Comment(text, commenter);
            commentCount++;
        }
    }

    void showPost(); // We'll define this later to avoid circular dependency

    ~Post() {
        for(int i = 0; i < commentCount; i++) delete comments[i];
        delete[] comments;
    }
};

class User {
    string username;
    Post** posts;
    int postCount;

public:
    User(string name) : username(name), postCount(0) {
        posts = new Post*[10];
    }

    void createPost(string content) {
        if (postCount < 10) {
            posts[postCount++] = new Post(content, this);
        }
    }

    string getName() { return username; }
    Post* getLatestPost() { return (postCount > 0) ? posts[postCount-1] : nullptr; }

    ~User() {
        for(int i = 0; i < postCount; i++) delete posts[i];
        delete[] posts;
    }
};
