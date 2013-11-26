/*
 * Open Chinese Convert
 *
 * Copyright 2010-2013 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Common.hpp"
#include "Dict.hpp"

namespace Opencc {
  class TextDict : public Dict {
  public:
    TextDict();
    virtual ~TextDict();
    virtual size_t KeyMaxLength() const;
    virtual Optional<DictEntry*> MatchPrefix(const char* word);
    virtual shared_ptr<vector<DictEntry*>> MatchAllPrefixes(const char* word);
    virtual shared_ptr<vector<DictEntry>> GetLexicon();
    void AddKeyValue(DictEntry entry);
    void LoadFromFile(const string fileName);
    void LoadFromDict(Dict& dictionary);

  private:
    void SortLexicon();

    bool sorted;
    size_t maxLength;
    shared_ptr<vector<DictEntry>> lexicon;
  };
}
