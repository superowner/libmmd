
/**
             Copyright itsuhane@gmail.com, 2012.
  Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
**/

inline Texture::Texture(const std::wstring &texture_path) : texture_path_(texture_path) {}
inline const std::wstring& Texture::GetTexturePath() const { return texture_path_; }
inline bool Texture::operator<(const Texture &texture) const { return texture_path_ <texture.texture_path_; }

inline const Texture& TextureRegistry::GetTexture(const std::wstring &texture_path) {
    std::pair<std::set<Texture>::iterator, bool> ret = registry_.insert(Texture(texture_path));
    return *ret.first;
}

inline void TextureRegistry::SetGlobalToonRootPath(std::wstring root_path) {
    root_path_ = root_path;
}

inline const Texture& TextureRegistry::GetGlobalToon(size_t toon_id) {
    if(toon_id<10) {
        return GetTexture(root_path_+CanonicalToonName(toon_id+1));
    } else {
        return GetTexture(root_path_+CanonicalToonName(0));
    }
}
