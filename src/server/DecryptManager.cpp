//
// Created by arthaox on 05/10/17.
//

#include "DecryptManager.hpp"

DecryptManager::DecryptManager()
{

}

DecryptManager::~DecryptManager()
{
}

bool DecryptManager::createKey()
{
  int			rep = 0;
  RSA			*r = NULL;
  BIGNUM		*bne = NULL;
  BIO			*bp_private = NULL;

  int             bits = 2048;
  unsigned long   e = RSA_F4;

  bne = BN_new();
  rep = BN_set_word(bne,e);
  if(rep != 1)
    goto free_all;

  r = RSA_new();
  rep = RSA_generate_key_ex(r, bits, bne, NULL);
  if(rep != 1)
    goto free_all;

  bp_private = BIO_new_file("PrivateKey.pem", "w+");
  rep = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);

  free_all:

  BIO_free_all(bp_private);
  RSA_free(r);
  BN_free(bne);

  return (rep == 1);
}

RSA * DecryptManager::createRSA(char *filename, int publi)
{
  FILE * fp = fopen(filename,"rb");

  if(fp == NULL)
  {
    std::cout << "Error: fail to open file :" << filename << std::endl;
    return NULL;
  }
  RSA *rsa= RSA_new() ;

  if(!publi)
  {
    rsa = PEM_read_RSAPrivateKey(fp, &rsa,NULL, NULL);
  }

  return rsa;
}

int DecryptManager::privateDecrypt(int data_len, unsigned char *enc_data,
				   RSA *key, unsigned char *decrypted)
{
  int  result = RSA_private_decrypt(data_len, enc_data, decrypted, key, this->padding_private);
  return result;
}
