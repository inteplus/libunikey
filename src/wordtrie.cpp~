#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#include "wordtrie.h"


int TrieNode_c::num_descendants() const {
  int cnt = 1;
  for(auto iter = m_children.begin(); iter != m_children.end(); iter++)
    cnt += iter->second->num_descendants();
  return cnt;
}

std::ostream & operator << (std::ostream &out, const TrieNode_c &c) {
  out << c.m_count << " " << int(c.m_endofword) << " " <<  c.m_children.size() << " ";
  for(auto iter = c.m_children.begin(); iter != c.m_children.end(); iter++)
    out << int(iter->first) << " " << *iter->second << " ";
  return out;
}

std::istream & operator >> (std::istream &in, TrieNode_c &c) {
  size_t n; // number of children
  int x;
  in >> c.m_count >> x >> n;
  c.m_endofword = bool(x);
  c.m_children.clear();
  while(n--) {
    TrieNode_p node = new TrieNode_c();
    in >> x >> *node;
    node->m_parent = &c;
    c.m_children[char(x)].reset(node);
  }
  return in;
}


void Trie_c::insert(std::string const& word, long long count) {
  TrieNode_p current = root();
  current->m_count += count;

  for(size_t i=0; i < word.size(); i++) {
    char ch = word[i];
    auto iter = current->m_children.find(ch);
    TrieNode_p node;

    if(iter != current->m_children.end())
      node = iter->second.get();
    else {
      node = new TrieNode_c();
      node->m_parent = current;
      current->m_children[ch].reset(node);
    }

    current = node;
    current->m_count += count;
  }

  current->m_endofword = true;
}


TrieNode_p Trie_c::search(std::string const& word) const {
  TrieNode_p current = root();
  for(size_t i=0; i < word.size(); i++) {
    char ch = word[i];
    auto iter = current->m_children.find(ch);

    if(iter == current->m_children.end())
      return nullptr;
    current = iter->second.get();
  }
  return current;
}

double Trie_c::prob(std::string const& word) const {
  TrieNode_p node = search(word);
  if(!node)
    return 0.0;
  return ((double) node->m_count) / total_count();
}

double Trie_c::cond_prob(std::string const& word) const {
  TrieNode_p node = search(word);
  if(!node)
    return 0.0;
  return ((double) node->m_count) / node->m_parent->m_count;
}

std::ostream& operator<<(std::ostream& out, const Trie_c& c) {
  return out << *c.m_root;
}

std::istream& operator>>(std::istream &in, Trie_c& c) {
  TrieNode_p node = new TrieNode_c();
  in >> *node;
  c.m_root.reset(node);
  return in;
}



void load_from_file(std::string const& filepath, Trie_c& out_trie) {
  std::ifstream ifs(filepath);
  ifs >> out_trie;
}


void save_to_file(std::string const& filepath, Trie_c const& in_trie) {
  std::ofstream ofs(filepath);
  ofs << in_trie;
}
