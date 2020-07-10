#ifndef WORD_TRIE_H
#define WORD_TRIE_H


#include <string>
#include <memory>
#include <map>
#include <iostream>


struct TrieNode_c;
typedef TrieNode_c* TrieNode_p;
typedef std::unique_ptr<TrieNode_c> TrieNode_lp;


struct TrieNode_c {
  std::map<char, TrieNode_lp> m_children;
  TrieNode_p m_parent;
  long long m_count;
  bool m_endofword;

  // constructor
  TrieNode_c() {
    m_parent = nullptr;
    m_count = 0;
    m_endofword = false;
  }

  // number of descendant nodes, including this node
  int num_descendants() const;


private: // serialisation
  friend std::ostream & operator <<(std::ostream &out, const TrieNode_c &c);
  friend std::istream & operator >>(std::istream &in, TrieNode_c &c);
};

// serialisation
std::ostream& operator <<(std::ostream& out, const TrieNode_c& c);
std::istream& operator >>(std::istream& in, TrieNode_c& c);


struct Trie_c {
  TrieNode_lp m_root;

  // constructor
  Trie_c() { m_root.reset(new TrieNode_c); }

  // root node
  inline TrieNode_p root() const { return m_root.get(); }

  // total count
  inline long long total_count() const { return m_root->m_count; }


  // count the number of nodes
  inline int num_nodes() const { return m_root->num_descendants(); }

  // inserts a word with count
  void insert(std::string const& word, long long count=1);

  // searches for a TrieNode_c representing a word
  TrieNode_p search(std::string const& word) const;

  // estimates the prior probability of a word
  double prob(std::string const& word) const;

  // estimates the probability of a word given its parent (ie without the last letter)
  double cond_prob(std::string const& word) const;


private: // serialisation
  friend std::ostream & operator << (std::ostream &out, const Trie_c &c);
  friend std::istream & operator >> (std::istream &in, Trie_c &c);
};

// serialisation
std::ostream & operator << (std::ostream &out, const Trie_c &c);
std::istream & operator >> (std::istream &in, Trie_c &c);


// loads a trie from file
void load_from_file(std::string const& filepath, Trie_c& out_trie);


// saves a trie to file
void save_to_file(std::string const& filepath, Trie_c const& in_trie);


#endif
