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
 18;
 0.00000;-0.03974;0.00000;,
 0.00000;0.00000;0.04500;,
 0.04500;0.00000;0.00000;,
 0.00000;0.00000;-0.04500;,
 -0.04500;0.00000;0.00000;,
 0.00000;0.18000;0.01560;,
 0.01559;0.18000;0.00001;,
 0.04500;0.00000;0.00000;,
 0.00000;0.00000;0.04500;,
 0.01559;0.18000;0.00001;,
 0.00000;0.18000;-0.01557;,
 0.00000;0.00000;-0.04500;,
 0.00000;0.18000;-0.01557;,
 -0.01559;0.18000;0.00001;,
 -0.04500;0.00000;0.00000;,
 -0.01559;0.18000;0.00001;,
 0.00000;0.18000;0.01560;,
 0.00000;0.00000;0.04500;;
 
 9;
 3;2,1,0;,
 3;3,2,0;,
 3;4,3,0;,
 3;1,4,0;,
 4;8,7,6,5;,
 4;7,11,10,9;,
 4;11,14,13,12;,
 4;14,17,16,15;,
 4;9,12,13,5;;
 
 MeshMaterialList {
  1;
  9;
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
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  13;
  0.679555;-0.276426;0.679555;,
  0.679570;-0.276379;-0.679558;,
  -0.679570;-0.276379;-0.679558;,
  0.551986;-0.624999;0.551986;,
  0.702437;0.114731;0.702437;,
  0.702441;0.114828;-0.702418;,
  -0.702441;0.114828;-0.702418;,
  0.551986;-0.624999;-0.551986;,
  -0.551986;-0.624999;-0.551986;,
  -0.551986;-0.624999;0.551986;,
  -0.679555;-0.276426;0.679555;,
  -0.702437;0.114731;0.702437;,
  0.000000;1.000000;-0.000000;;
  9;
  3;0,0,3;,
  3;1,1,7;,
  3;2,2,8;,
  3;10,10,9;,
  4;0,0,4,4;,
  4;1,1,5,5;,
  4;2,2,6,6;,
  4;10,10,11,11;,
  4;12,12,12,12;;
 }
 MeshTextureCoords {
  18;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.081700;0.346380;,
  0.168300;0.346380;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.346380;,
  0.336600;0.346390;,
  0.500000;1.000000;,
  0.418300;0.346390;,
  0.504890;0.346380;,
  0.750000;1.000000;,
  0.586600;0.346380;,
  0.673190;0.346380;,
  1.000000;1.000000;;
 }
}
