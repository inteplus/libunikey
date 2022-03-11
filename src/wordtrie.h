#ifndef LIBUNIKEY_WORD_TRIE_H
#define LIBUNIKEY_WORD_TRIE_H


#include <string>
#include <memory>
#include <map>


struct TrieNode_c;
typedef TrieNode_c* TrieNode_p;
typedef std::unique_ptr<TrieNode_c> TrieNode_lp;


struct TrieNode_c {
  std::map<char, TrieNode_lp> m_children;
  TrieNode_p m_parent;
  double m_en_prob;
  double m_vi_prob;

  // constructor
  TrieNode_c() {
    m_parent = nullptr;
    m_en_prob = 0.0;
    m_vi_prob = 0.0;
  }
};


struct Trie_c {
  TrieNode_lp m_root;

  // constructor
  Trie_c() { m_root.reset(new TrieNode_c); }

  // root node
  inline TrieNode_p root() const { return m_root.get(); }

  // inserts a word with count
  void insert(std::string const& word, double en_prob=0.0, double vi_prob=0.0);

  // searches for a TrieNode_c representing a word
  TrieNode_p search(std::string const& word) const;
};


#endif
