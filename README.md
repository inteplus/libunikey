# libunikey

Continuation of Pham Kim Long's libunikey engine, upgraded to C++11, and with Envi, a modified Telex input method for typing both English and Vietnamese conveniently.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese more easily than Telex. You type:

Single key stroke for a tone with lowest probability of hitting an English bigram

  * Q (0.001030) for sắc
  * Z (0.001142) for huyền
  * X (0.001933) for ngã
  * J (0.002077) for nặng
  * K (0.008084) for hỏi

Single suffix key to form a Vietnamese letter with very low probability of hitting an English bigram

  * aa (0.000398) for â
  * aw (0.000906) for ă
  * ee (0.004278) for ê
  * oo (0.002352) for ô
  * op (0.002419) for ơ
  * uu (0.000015) for ư
  * dd (0.000925) for đ

These letters were chosen to minimise the probability of hitting an English bigram (using the English and Vietnamese Wikipedia corpora) and to preserve/enhance the fast typing pace of Telex.

-- Minh-Tri Pham
2019/09/23
