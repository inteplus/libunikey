#include "wordtrie.h"


void Trie_c::insert(std::string const& word, double en_prob, double vi_prob) {
  TrieNode_p current = root();

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
  }

  current->m_en_prob = en_prob;
  current->m_vi_prob = vi_prob;
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
