// Refer to Fast Inverse Square Root
float qurt(float x)
{
   union {
      float f;
      uint32_t i;
   } conv;
   float x2;
   const float threehalfs = 1.5F;
   
   x2 = x * 0.5F;
   conv.f = x;
   conv.i = 0x5F375A86 - ( conv.i >> 1 );
   conv.f = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );   
   conv.f = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
   
   x2 = conv.f * 0.5F;
   conv.i = 0x5F375A86 - ( conv.i >> 1 );
   conv.f = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );   
   conv.f = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
   return conv.f;
}