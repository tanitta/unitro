xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 146;
 0.00000;-0.52500;-0.50000;,
 0.43301;-0.52500;-0.25000;,
 0.43301;-0.44639;-0.25000;,
 0.00000;-0.44639;-0.50000;,
 0.43301;-0.52500;-0.25000;,
 0.43301;-0.52500;0.25000;,
 0.43301;-0.44639;0.25000;,
 0.43301;-0.44639;-0.25000;,
 -0.43301;-0.52500;0.25000;,
 -0.43301;-0.52500;-0.25000;,
 -0.43301;-0.44639;-0.25000;,
 -0.43301;-0.44639;0.25000;,
 -0.43301;-0.52500;-0.25000;,
 0.00000;-0.52500;-0.50000;,
 0.00000;-0.44639;-0.50000;,
 -0.43301;-0.44639;-0.25000;,
 0.00000;-0.47464;0.00000;,
 0.43301;-0.52500;-0.25000;,
 0.00000;-0.52500;-0.50000;,
 0.43301;-0.52500;0.25000;,
 0.43301;-0.52500;-0.25000;,
 -0.43301;-0.52500;-0.25000;,
 -0.43301;-0.52500;0.25000;,
 0.00000;-0.52500;-0.50000;,
 -0.43301;-0.52500;-0.25000;,
 0.00000;-0.39603;0.00000;,
 0.00000;-0.44639;-0.50000;,
 0.43301;-0.44639;-0.25000;,
 0.43301;-0.44639;-0.25000;,
 0.43301;-0.44639;0.25000;,
 -0.43301;-0.44639;0.25000;,
 -0.43301;-0.44639;-0.25000;,
 -0.43301;-0.44639;-0.25000;,
 0.00000;-0.44639;-0.50000;,
 0.08384;-0.52500;0.45160;,
 0.08384;-0.44639;0.45160;,
 0.43301;-0.52500;0.25000;,
 -0.08384;-0.52500;0.45160;,
 -0.43301;-0.52500;0.25000;,
 -0.43301;-0.44639;0.25000;,
 -0.08384;-0.44639;0.45160;,
 0.05156;-0.47464;0.06366;,
 0.05156;-0.39603;0.06366;,
 0.05156;-0.44639;0.43296;,
 0.05156;-0.52500;0.43296;,
 0.00000;-0.47464;0.02638;,
 0.00000;-0.39603;0.02500;,
 0.01428;-0.39603;0.02500;,
 0.01428;-0.47464;0.02638;,
 -0.05156;-0.39603;0.06366;,
 -0.05156;-0.47464;0.06366;,
 -0.05156;-0.52500;0.43296;,
 -0.05156;-0.44639;0.43296;,
 -0.01428;-0.47464;0.02638;,
 -0.01428;-0.39603;0.02500;,
 0.00000;-0.39603;0.02500;,
 0.00000;-0.47464;0.02638;,
 0.05156;-0.52500;0.43296;,
 0.08384;-0.44639;0.45160;,
 -0.08384;-0.44639;0.45160;,
 -0.05156;-0.44639;0.43296;,
 -0.08384;-0.52500;0.45160;,
 0.01428;-0.47464;0.02638;,
 0.05156;-0.39603;0.06366;,
 -0.01428;-0.47464;0.02638;,
 -0.05156;-0.47464;0.06366;,
 0.01428;-0.47464;0.02638;,
 0.00000;-0.47464;0.00000;,
 0.00000;-0.47464;0.02638;,
 -0.01428;-0.47464;0.02638;,
 0.00000;-0.39603;0.02500;,
 -0.01428;-0.39603;0.02500;,
 0.00000;-0.39603;0.00000;,
 0.01428;-0.39603;0.02500;,
 0.43301;-0.44639;0.25000;,
 0.05156;-0.39603;0.06366;,
 0.01428;-0.39603;0.02500;,
 0.00000;-0.39603;0.00000;,
 0.08384;-0.44639;0.45160;,
 0.05156;-0.44639;0.43296;,
 -0.05156;-0.39603;0.06366;,
 -0.05156;-0.44639;0.43296;,
 -0.08384;-0.44639;0.45160;,
 -0.43301;-0.44639;0.25000;,
 -0.01428;-0.39603;0.02500;,
 -0.01428;-0.47464;0.02638;,
 0.00000;-0.47464;0.00000;,
 -0.43301;-0.52500;0.25000;,
 -0.05156;-0.47464;0.06366;,
 0.05156;-0.47464;0.06366;,
 0.43301;-0.52500;0.25000;,
 0.01428;-0.47464;0.02638;,
 0.05156;-0.52500;0.43296;,
 0.08384;-0.52500;0.45160;,
 -0.08384;-0.52500;0.45160;,
 -0.05156;-0.52500;0.43296;,
 -0.02818;0.00000;-0.00246;,
 0.00246;0.00000;-0.02818;,
 0.02818;-0.00000;0.00246;,
 -0.00246;0.00000;0.02818;,
 -0.02085;-0.06399;-0.07449;,
 0.00246;0.00000;-0.02818;,
 -0.02818;0.00000;-0.00246;,
 -0.06680;-0.06394;-0.03591;,
 0.01530;-0.08495;-0.03140;,
 0.00246;0.00000;-0.02818;,
 -0.02085;-0.06399;-0.07449;,
 -0.03065;-0.08491;0.00718;,
 -0.00246;0.00000;0.02818;,
 0.02818;-0.00000;0.00246;,
 0.01530;-0.08495;-0.03140;,
 -0.06680;-0.06394;-0.03591;,
 -0.02818;0.00000;-0.00246;,
 -0.03065;-0.08491;0.00718;,
 -0.07706;-0.14539;-0.05324;,
 -0.03612;-0.14539;-0.08759;,
 -0.03612;-0.14539;-0.08759;,
 -0.00202;-0.15323;-0.04704;,
 -0.00202;-0.15323;-0.04704;,
 -0.04305;-0.15323;-0.01262;,
 -0.04305;-0.15323;-0.01262;,
 -0.07706;-0.14539;-0.05324;,
 -0.07689;-0.23493;-0.05858;,
 -0.04141;-0.23493;-0.08835;,
 -0.04141;-0.23493;-0.08835;,
 -0.01160;-0.23263;-0.05288;,
 -0.01160;-0.23263;-0.05288;,
 -0.04714;-0.23263;-0.02306;,
 -0.04714;-0.23263;-0.02306;,
 -0.07689;-0.23493;-0.05858;,
 -0.05522;-0.36372;-0.04108;,
 -0.01108;-0.47453;0.00327;,
 0.00807;-0.47453;-0.01280;,
 -0.02795;-0.36372;-0.06397;,
 -0.02795;-0.36372;-0.06397;,
 0.00807;-0.47453;-0.01280;,
 0.02103;-0.45974;0.00265;,
 -0.00623;-0.35263;-0.03805;,
 -0.00623;-0.35263;-0.03805;,
 0.02103;-0.45974;0.00265;,
 0.00188;-0.45974;0.01872;,
 -0.03346;-0.35263;-0.01520;,
 -0.03346;-0.35263;-0.01520;,
 0.00188;-0.45974;0.01872;,
 -0.01108;-0.47453;0.00327;,
 -0.05522;-0.36372;-0.04108;;
 
 55;
 4;3,2,1,0;,
 4;7,6,5,4;,
 4;11,10,9,8;,
 4;15,14,13,12;,
 3;18,17,16;,
 3;20,19,16;,
 3;22,21,16;,
 3;24,23,16;,
 3;27,26,25;,
 3;29,28,25;,
 3;31,30,25;,
 3;33,32,25;,
 4;36,6,35,34;,
 4;40,39,38,37;,
 4;44,43,42,41;,
 4;48,47,46,45;,
 4;52,51,50,49;,
 4;56,55,54,53;,
 4;58,43,57,34;,
 4;61,51,60,59;,
 4;63,47,62,41;,
 4;65,64,54,49;,
 3;68,67,66;,
 3;68,69,67;,
 3;72,71,70;,
 3;70,73,72;,
 4;77,76,75,74;,
 4;75,79,78,74;,
 4;83,82,81,80;,
 4;83,80,84,77;,
 4;88,87,86,85;,
 4;91,86,90,89;,
 4;90,93,92,89;,
 4;95,94,87,88;,
 4;99,98,97,96;,
 4;103,102,101,100;,
 4;106,105,98,104;,
 4;110,109,108,107;,
 4;113,99,112,111;,
 4;103,100,115,114;,
 4;106,104,117,116;,
 4;110,107,119,118;,
 4;113,111,121,120;,
 4;114,115,123,122;,
 4;116,117,125,124;,
 4;118,119,127,126;,
 4;120,121,129,128;,
 4;133,132,131,130;,
 4;122,123,133,130;,
 4;137,136,135,134;,
 4;124,125,137,134;,
 4;141,140,139,138;,
 4;126,127,141,138;,
 4;145,144,143,142;,
 4;128,129,145,142;;
 
 MeshMaterialList {
  1;
  55;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Body.png";
   }
  }
 }
 MeshNormals {
  64;
  0.000000;-0.997726;0.067399;,
  0.500000;0.000000;-0.866026;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.000000;0.997796;-0.066355;,
  0.000000;0.017590;0.999845;,
  0.499999;-0.000000;0.866026;,
  -0.499999;0.000000;0.866026;,
  -0.925609;0.003298;0.378468;,
  -0.386880;0.012848;0.922040;,
  0.925607;0.003296;0.378471;,
  0.386877;0.012846;0.922042;,
  -0.500000;0.000000;-0.866026;,
  -0.086790;-0.994966;0.050108;,
  0.000000;-0.994966;0.100217;,
  -0.106899;-0.994188;0.012751;,
  0.086790;-0.994966;0.050108;,
  0.106900;-0.994188;0.012753;,
  0.000000;0.994966;-0.100217;,
  0.086790;0.994966;-0.050108;,
  0.106357;0.994263;-0.011370;,
  -0.106358;0.994263;-0.011372;,
  -0.086790;0.994966;-0.050108;,
  -0.499982;0.000000;0.866036;,
  0.499994;-0.000000;0.866029;,
  -0.103474;-0.991064;0.084178;,
  0.000000;-1.000000;0.000000;,
  0.103475;-0.991063;0.084181;,
  0.000000;1.000000;-0.000000;,
  -0.102681;0.991321;-0.082098;,
  0.102679;0.991321;-0.082095;,
  0.101688;0.994668;-0.017148;,
  -0.003498;0.991635;0.129024;,
  -0.101689;0.994668;-0.017151;,
  0.003499;0.991635;0.129024;,
  0.102504;-0.994547;0.019236;,
  -0.102503;-0.994547;0.019233;,
  0.003498;-0.991635;-0.129024;,
  -0.003499;-0.991635;-0.129024;,
  -0.280381;0.899813;-0.334251;,
  0.000000;1.000000;-0.000000;,
  -0.560206;-0.490378;-0.667606;,
  0.778044;-0.038162;-0.627050;,
  0.585145;0.413903;0.697345;,
  -0.577779;0.438159;-0.688613;,
  0.769985;0.050368;-0.636070;,
  0.602771;-0.347314;0.718359;,
  -0.636373;0.141346;-0.758321;,
  0.760735;-0.041091;-0.647760;,
  0.625882;-0.227755;0.745922;,
  -0.640630;-0.082253;-0.763431;,
  0.766713;-0.041882;-0.640622;,
  0.642759;-0.005137;0.766051;,
  -0.601411;-0.353043;-0.716705;,
  0.774099;-0.039993;-0.631800;,
  0.618669;0.271321;0.737315;,
  0.775199;0.140545;-0.615884;,
  0.596228;-0.373646;0.710564;,
  -0.763509;0.027989;0.645190;,
  -0.750719;0.096078;0.653597;,
  -0.770023;-0.041084;0.636692;,
  -0.764030;-0.041874;0.643820;,
  -0.756624;-0.039991;0.652626;,
  -0.752630;-0.038164;0.657336;;
  55;
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;12,12,12,12;,
  3;14,13,0;,
  3;13,15,0;,
  3;17,16,0;,
  3;16,14,0;,
  3;19,18,4;,
  3;20,19,4;,
  3;22,21,4;,
  3;18,22,4;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;3,3,8,8;,
  4;9,9,5,5;,
  4;2,2,10,10;,
  4;5,5,11,11;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;8,9,9,8;,
  4;10,11,11,10;,
  3;26,0,25;,
  3;26,27,0;,
  3;4,29,28;,
  3;28,30,4;,
  4;4,30,31,20;,
  4;31,32,32,20;,
  4;21,34,34,33;,
  4;21,33,29,4;,
  4;35,17,0,27;,
  4;25,0,15,36;,
  4;15,37,37,36;,
  4;38,38,17,35;,
  4;40,40,39,39;,
  4;44,39,39,44;,
  4;45,56,56,45;,
  4;46,57,57,46;,
  4;58,59,59,58;,
  4;44,44,47,47;,
  4;45,45,48,48;,
  4;46,46,49,49;,
  4;58,58,60,60;,
  4;47,47,50,50;,
  4;48,48,51,51;,
  4;49,49,52,52;,
  4;60,60,61,61;,
  4;53,41,41,53;,
  4;50,50,53,53;,
  4;54,42,42,54;,
  4;51,51,54,54;,
  4;55,43,43,55;,
  4;52,52,55,55;,
  4;62,63,63,62;,
  4;61,61,62,62;;
 }
 MeshTextureCoords {
  146;
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.501040;0.000850;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.501040;0.000850;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.000000;0.200000;,
  0.200000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.200000;0.000000;,
  0.000000;0.200000;,
  0.200000;0.000000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.480160;0.000000;,
  0.750000;0.000000;,
  0.500000;0.000000;,
  0.519840;0.000000;,
  0.495040;1.000000;,
  0.519840;1.000000;,
  0.750000;1.000000;,
  0.480160;1.000000;,
  0.504070;-0.019790;,
  0.094490;0.986410;,
  0.012220;1.084930;,
  -0.046110;1.122810;,
  0.953840;0.897400;,
  0.912830;0.982570;,
  0.094490;0.986410;,
  0.912830;0.982570;,
  0.953840;0.897400;,
  0.504070;-0.019790;,
  0.012220;1.084930;,
  0.012220;1.084930;,
  -0.046110;1.122810;,
  0.504070;-0.019790;,
  0.094490;0.986410;,
  0.094490;0.986410;,
  0.504070;-0.019790;,
  0.012220;1.084930;,
  0.912830;0.982570;,
  0.953840;0.897400;,
  0.953840;0.897400;,
  0.912830;0.982570;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.869880;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.869920;,
  1.000000;0.869870;,
  0.000000;1.000000;,
  0.000000;0.869880;,
  1.000000;0.869910;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.869870;,
  1.000000;0.869920;,
  1.000000;1.000000;,
  0.000000;0.869910;,
  0.000000;0.810240;,
  1.000000;0.810230;,
  0.000000;0.810230;,
  1.000000;0.811290;,
  0.000000;0.811290;,
  1.000000;0.811290;,
  0.000000;0.811290;,
  1.000000;0.810240;,
  0.000000;0.745430;,
  1.000000;0.745430;,
  0.000000;0.745430;,
  1.000000;0.746150;,
  0.000000;0.746150;,
  1.000000;0.746160;,
  0.000000;0.746160;,
  1.000000;0.745430;,
  0.000000;0.648080;,
  0.000000;0.551710;,
  1.000000;0.551710;,
  1.000000;0.648080;,
  0.000000;0.648080;,
  0.000000;0.551710;,
  1.000000;0.551710;,
  1.000000;0.647610;,
  0.000000;0.647610;,
  0.000000;0.551710;,
  1.000000;0.551710;,
  1.000000;0.647610;,
  0.000000;0.647610;,
  0.000000;0.551710;,
  1.000000;0.551710;,
  1.000000;0.648080;;
 }
}
