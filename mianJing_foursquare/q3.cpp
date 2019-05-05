////Write a one-page design doc describing a service that keeps track of Foursquare users as they check in at
////different venues. In particular, this service will get informed of each check-in in real time (a user/venue
////pair) and must be able to answer the following queries in real time:
////    1. Where is user A right now?
////    2. What users are at venue X right now?
////The following business rules apply:
////    1. A user can only be at one venue at a time. If user A checks in at venue X and then at venue Y, they are
////    no longer at venue X.
////    2. A check-in only “lasts” for at most 3 hours. If user A checks in at venue X and then does nothing for 3
////    hours, they are no longer at venue X.
//
//
//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//#include <list>
//#include <time.h>
//
//using namespace std;
//
//class User {
//    string user_id;
//    Checkin* checkin_p;     // most recent checkin pointer
//    list<Checkin*>::iterator iter;  // checkin venue list iterator
//public:
//    User(string& id): user_id(id), checkin_p(nullptr) {};
//    string getUserId() {
//        return user_id;
//    }
//
//    // If checkin is available, return its corresponding venue_id
//    string getCheckinVenue() {
//        return checkin_p ? checkin_p->venue_p->getVenueId() : "";
//    }
//
//    // If user checkins at another venue, update its checkin.
//    void updateCheckin(Checkin* p) {
//        if (checkin_p)
//            checkin_p->venue_p->getCheckins().erase(iter);
//        checkin_p = p;
//        iter = p->venue_p->getCheckins().begin();
//    }
//
//    // If user's most recent checkin expires, reset checkin_p to null.
//    void updateStatus(long start) {
//        if (checkin_p && checkin_p->timestamp < start) {
//            checkin_p->venue_p->getCheckins().erase(iter);
//            checkin_p = nullptr;
//        }
//    }
//
//};
//
//
//struct Checkin {
//    string checkin_id;
//    User* user_p;
//    Venue* venue_p;
//    long timestamp;
//    Checkin(string& id, User* u, Venue* v, long time): checkin_id(id), user_p(u), venue_p(v), timestamp(time) {};
//};
//
//
//class Venue {
//    string venue_id;
//    list<Checkin*> checkins;
//public:
//    Venue(string& id): venue_id(id) {};
//    string getVenueId() {
//        return venue_id;
//    }
//    list<Checkin*> getCheckins() {
//        return checkins;
//    }
//
//    // return all the users that checked-in here in the past 3 hours.
//    unordered_set<string> getUsers() {
//        unordered_set<string> users;
//        for (Checkin* p : checkins)
//            users.insert(p->user_p->getUserId());
//        return users;
//    }
//
//    // Pop out those expired checkins from the list.
//    void filterExpired(long start) {
//        list<Checkin*>::reverse_iterator iter = checkins.rbegin();
//        while (iter != checkins.rend() && (*iter)->timestamp < start) {
//            checkins.pop_back();
//            iter = checkins.rbegin();
//        }
//    }
//
//    // Whenever a new checkin appears, push it to the front of the list.
//    void addCheckin(Checkin* checkin) {
//        checkins.push_front(checkin);
//    }
//};
//
//class Scheduler {
//public:
//    Scheduler() {};
//    // Periodically check and pop out all the expired checkins in each venue.
//    void check(long start, unordered_map<string, Venue*>& venues) {
//        for (auto&& pair : venues)
//            pair.second->filterExpired(start);
//    }
//};
//
//
//class CheckinSystem {
//    unordered_map<string, User*> users;
//    unordered_map<string, Venue*> venues;
//    long duration = 10800;      // Expiration duration, 3 hours in seconds
//public:
//    string genCheckinId(string& user_id, string& venue_id, long time) {};
//
//    // Whenever a user makes a new checkin. venue add this checkin, and user update his checkin status.
//    void userCheckIn(string& user_id, string& venue_id, long time) {
//        string checkin_id = genCheckinId(user_id, venue_id, time);
//        Checkin checkin(checkin_id, users[user_id], venues[venue_id], time);
//        venues[venue_id]->addCheckin(&checkin);
//        users[user_id]->updateCheckin(&checkin);
//    }
//
//    // Return user's current checkin venue if available.
//    string getUserCheckinVenue(string& user_id, long time) {
//        long start = time - duration;
//        users[user_id]->updateStatus(start);
//        return users[user_id]->getCheckinVenue();
//    }
//
//    // Return venue's all available checked-in users.
//    unordered_set<string> getVenueCheckinUsers(string& venue_id, long time) {
//        long start = time - duration;
//        venues[venue_id]->filterExpired(start);
//        return venues[venue_id]->getUsers();
//    }
//};