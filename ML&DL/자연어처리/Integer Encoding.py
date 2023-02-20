from nltk.tokenize import sent_tokenize
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

raw_text = "A barber is a person. a barber is good person. a barber is huge person. he Knew A Secret! The Secret He Kept is huge secret. Huge secret. His barber kept his word. a barber kept his word. His barber kept his secret. But keeping and keeping such a huge secret to himself was driving the barber crazy. the barber went up a huge mountain."

# 문장 토큰화
sentences = sent_tokenize(raw_text)
print(sentences)   # raw_text가 문장 단위로 토큰화 된 것 확인

# 정제작업 및 정규화 작업으로 단어 토큰화
'''
단어들을 소문자화하여 단어의 개수를 통일
불용어와 단어 길이가 2 이하인 경우에 대해서 단어를 일부 제외
'''
vocab = {}
preprocessed_sentences = []
stop_words = set(stopwords.words('english'))

for sentence in sentences:
    # 단어 토큰화
    tokenized_sentence = word_tokenize(sentence)
    result = []

    for word in tokenized_sentence:
        word = word.lower()  # 모든 단어를 소문자화
        if word not in stop_words:  # 단어 토큰화 결과에 대해 불용어를 제거
            if len(word) > 2:       # 단어 길이가 2 이하인 경우도 제거
                result.append(word)
                if word not in vocab:
                    vocab[word] = 0
                vocab[word] += 1
    preprocessed_sentences.append(result)
print(preprocessed_sentences)
print('단어 집합 :', vocab)
print('단어 barber 빈도수 :', vocab["barber"])

vocab_sorted = sorted(vocab.items(), key = lambda x:x[1], reverse=True) # 빈도수가 높은 순으로 정렬
print(vocab_sorted)

# 높은 빈도수를 가진 단어부터 낮은 정수(1)부터 부여
word_to_index = {}
i = 0
for (word, frequency) in vocab_sorted:
    if frequency > 1:   # 빈도수가 적은 단어는 제외 -> 빈도수가 낮은 단어는 자연어 처리에서 의미를 가지지 않을 가능성이 높기 때문
        i += 1
        word_to_index[word] = i
print(word_to_index)

# 빈도수 상위 n개의 단어만 사용
vocab_size = 5
words_frequency = [word for word, index in word_to_index.items() if index >= vocab_size + 1]

for w in words_frequency:
    del word_to_index[w]
print(word_to_index)

# OOV 문제는 어떻게?
word_to_index['OOV'] = len(word_to_index) + 1
print(word_to_index)

# word_to_index를 사용하여 sentences의 모든 단어들을 맵핑되는 정수로 인코딩하기
encoded_sentences = []
for sentence in preprocessed_sentences:
    encoded_sentence = []
    for word in sentence:
        try:
            encoded_sentence.append(word_to_index[word])
        except KeyError:
            # 단어 집합에 없는 단어라면 'OOV'의 정수를 리턴
            encoded_sentence.append(word_to_index['OOV'])
    encoded_sentences.append(encoded_sentence)
print(encoded_sentences)

'''
Python의 Dictionary 자료형으로 정수 인코딩을 했지만
좀 더 쉽게 하기 위해서 Counter, FreqDist, enumerate를 사용하거나
케라스 토크나이저를 사용할 수 있음.
'''
# Counter 사용하기
from collections import Counter

all_words_list = sum(preprocessed_sentences, []) # 단어 집합을 만들기 위해서 문장 경계인 , 를 제거하고 단어들을 하나의 리스트로 만들기
vocab1 = Counter(all_words_list)
print(vocab1)

# NLTK의 FreqDist 사용하기
from nltk import FreqDist
import numpy as np
vocab2 = FreqDist(np.hstack(preprocessed_sentences)) # np.hstack으로 문장 구분을 제거
print(vocab2["barber"])
vocab2 = vocab2.most_common(vocab_size)
print(vocab2)

# enumerate 사용
word_to_index1 = {word[0] : index + 1 for index, word in enumerate(vocab)}
print(word_to_index1)