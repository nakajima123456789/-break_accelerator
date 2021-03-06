xof 0303txt 0032
template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}


Frame group {
 

 FrameTransformMatrix {
  0.393701,0.000000,0.000000,0.000000,0.000000,-0.000000,-0.393701,0.000000,0.000000,0.393701,-0.000000,0.000000,0.000000,0.431623,0.000000,1.000000;;
 }

 Frame pasted__group {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,-3.962772,-0.000000,0.239086,1.000000;;
  }

  Frame pasted__pasted__pCube3 {
   

   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,3.962772,-0.000000,-1.100083,1.000000;;
   }

   Mesh pasted__pasted__pCube3 {
    54;
    -0.480000;0.480000;0.265131;,
    0.000000;0.480000;0.745131;,
    0.000000;0.480000;0.265131;,
    -0.480000;0.480000;0.745131;,
    0.480000;0.480000;0.745131;,
    0.480000;0.480000;0.265131;,
    0.000000;0.480000;1.225131;,
    -0.480000;0.480000;1.225131;,
    0.480000;0.480000;1.225131;,
    -0.480000;0.480000;1.225131;,
    0.000000;0.000000;1.225131;,
    0.000000;0.480000;1.225131;,
    -0.480000;0.000000;1.225131;,
    0.480000;0.000000;1.225131;,
    0.480000;0.480000;1.225131;,
    0.000000;-0.480000;1.225131;,
    -0.480000;-0.480000;1.225131;,
    0.480000;-0.480000;1.225131;,
    -0.480000;-0.480000;1.225131;,
    0.000000;-0.480000;0.745131;,
    0.000000;-0.480000;1.225131;,
    -0.480000;-0.480000;0.745131;,
    0.480000;-0.480000;0.745131;,
    0.480000;-0.480000;1.225131;,
    0.000000;-0.480000;0.265131;,
    -0.480000;-0.480000;0.265131;,
    0.480000;-0.480000;0.265131;,
    -0.480000;-0.480000;0.265131;,
    0.000000;0.000000;0.265131;,
    0.000000;-0.480000;0.265131;,
    -0.480000;0.000000;0.265131;,
    0.480000;0.000000;0.265131;,
    0.480000;-0.480000;0.265131;,
    0.000000;0.480000;0.265131;,
    -0.480000;0.480000;0.265131;,
    0.480000;0.480000;0.265131;,
    0.480000;0.000000;0.265131;,
    0.480000;-0.480000;0.745131;,
    0.480000;-0.480000;0.265131;,
    0.480000;0.000000;0.745131;,
    0.480000;0.480000;0.265131;,
    0.480000;0.480000;0.745131;,
    0.480000;-0.480000;1.225131;,
    0.480000;0.000000;1.225131;,
    0.480000;0.480000;1.225131;,
    -0.480000;-0.480000;0.265131;,
    -0.480000;0.000000;0.745131;,
    -0.480000;0.000000;0.265131;,
    -0.480000;-0.480000;0.745131;,
    -0.480000;0.480000;0.745131;,
    -0.480000;0.480000;0.265131;,
    -0.480000;0.000000;1.225131;,
    -0.480000;-0.480000;1.225131;,
    -0.480000;0.480000;1.225131;;
    48;
    3;0,1,2;,
    3;1,0,3;,
    3;2,4,5;,
    3;4,2,1;,
    3;3,6,1;,
    3;6,3,7;,
    3;1,8,4;,
    3;8,1,6;,
    3;9,10,11;,
    3;10,9,12;,
    3;11,13,14;,
    3;13,11,10;,
    3;12,15,10;,
    3;15,12,16;,
    3;10,17,13;,
    3;17,10,15;,
    3;18,19,20;,
    3;19,18,21;,
    3;20,22,23;,
    3;22,20,19;,
    3;21,24,19;,
    3;24,21,25;,
    3;19,26,22;,
    3;26,19,24;,
    3;27,28,29;,
    3;28,27,30;,
    3;29,31,32;,
    3;31,29,28;,
    3;30,33,28;,
    3;33,30,34;,
    3;28,35,31;,
    3;35,28,33;,
    3;36,37,38;,
    3;37,36,39;,
    3;40,39,36;,
    3;39,40,41;,
    3;39,42,37;,
    3;42,39,43;,
    3;41,43,39;,
    3;43,41,44;,
    3;45,46,47;,
    3;46,45,48;,
    3;47,49,50;,
    3;49,47,46;,
    3;48,51,46;,
    3;51,48,52;,
    3;46,53,49;,
    3;53,46,51;;

    MeshTextureCoords {
     54;
     0.582728;0.647680;,
     0.747468;0.482940;,
     0.747468;0.647680;,
     0.582728;0.482940;,
     0.912208;0.482940;,
     0.912208;0.647680;,
     0.747468;0.318200;,
     0.582728;0.318200;,
     0.912208;0.318200;,
     0.054637;0.645425;,
     0.219377;0.480685;,
     0.219377;0.645425;,
     0.054637;0.480685;,
     0.384117;0.480685;,
     0.384117;0.645425;,
     0.219377;0.315945;,
     0.054637;0.315945;,
     0.384117;0.315945;,
     0.912208;0.318200;,
     0.747468;0.482940;,
     0.747468;0.318200;,
     0.912208;0.482940;,
     0.582728;0.482940;,
     0.582728;0.318200;,
     0.747468;0.647680;,
     0.912208;0.647680;,
     0.582728;0.647680;,
     0.054637;0.645425;,
     0.219377;0.480685;,
     0.219377;0.645425;,
     0.054637;0.480685;,
     0.384117;0.480685;,
     0.384117;0.645425;,
     0.219377;0.315945;,
     0.054637;0.315945;,
     0.384117;0.315945;,
     0.747468;0.647680;,
     0.912208;0.482940;,
     0.912208;0.647680;,
     0.747468;0.482940;,
     0.582728;0.647680;,
     0.582728;0.482940;,
     0.912208;0.318200;,
     0.747468;0.318200;,
     0.582728;0.318200;,
     0.582728;0.647680;,
     0.747468;0.482940;,
     0.747468;0.647680;,
     0.582728;0.482940;,
     0.912208;0.482940;,
     0.912208;0.647680;,
     0.747468;0.318200;,
     0.582728;0.318200;,
     0.912208;0.318200;;
    }

    MeshMaterialList {
     1;
     48;
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
     0;

     Material {
      1.000000;1.000000;1.000000;1.000000;;
      0.000000;
      0.000000;0.000000;0.000000;;
      0.000000;0.000000;0.000000;;

      TextureFilename {
       R_BOX.png;
      }
     }
    }

    VertexDuplicationIndices {
     54;
     26;
     0,
     1,
     2,
     3,
     4,
     5,
     6,
     7,
     8,
     7,
     10,
     6,
     12,
     13,
     8,
     15,
     16,
     17,
     16,
     19,
     15,
     21,
     22,
     17,
     24,
     25,
     26,
     25,
     28,
     24,
     30,
     31,
     26,
     2,
     0,
     5,
     31,
     22,
     26,
     39,
     5,
     4,
     17,
     13,
     8,
     25,
     46,
     30,
     21,
     3,
     0,
     12,
     16,
     7;
    }
   }
  }
 }
}