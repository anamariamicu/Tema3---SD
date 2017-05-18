#ifndef __STRUCT_H__
#define __STRUCT_H__

struct movie {
  std::string name;
  std::string id;
  int timestamp;
  std::string director;
  std::vector<std::string> actor_ids; // ?
  std::vector<std::string> categories;
  int number_ratings;
  int total_rating;

  movie(std::string name, std::string id, int timestamp, std::vector<std::string> categories,
  	    std::string director, std::vector<std::string> actor_ids);
  void add_rating(int rating);
  void remove_rating(int rating);
  std::string get_rating();
  int get_year();
};

struct user {
  std::string name;
  std::string id;
  std::unordered_map<std::string, int> ratings;

  user(std::string name, std::string id);
  void add_rating(std::string movie_id, int rating);
  int remove_rating(std::string movie_id);
};

struct actor {
  std::string name;
  std::string id;
  struct movie *first_movie;
  struct movie *last_movie;

  actor(std::string name, std::string id);
  actor(std::string id);
  void add_movie(struct movie*, struct actor**);
  int career_timestamp();
};

struct director {
	std::string name;
	unsigned int number_actors;

	director(std::string name, unsigned int number_actors);
};

struct ratings {
	int number_ratings;
	int total_rating;

	ratings();
	ratings(int rating);
	void add_rating(int rating);
	double get_average_rating();
};
#endif