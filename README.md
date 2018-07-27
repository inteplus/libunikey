# libunikey

Continuation of Pham Kim Long's libunikey engine, upgraded to C++11, and with Envi, a modified Telex input method for typing both English and Vietnamese conveniently.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese more easily than Telex. You type:
* aa for â (like Telex)
* aw for ă (like Telex)
* ee for ê (like Telex)
* dd for đ (like Telex)
* oo for ô
* ol for ơ
* uu for ư
* k for acute tone (sắc)
* z for grave tone (huyền)
* q for hook tone (hỏi)
* x for tilde tone (ngã) (like Telex)
* j for dot tone (nặng) (like Telex)
These letters were chosen to minimise the probability of hitting an English bigram (using the English and Vietnamese Wikipedia corpora) and to preserve/enhance the fast typing pace of Telex.

-- Minh-Tri Pham
2018/07/25
