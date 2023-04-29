function[correct]=inertial(angles,data)
    % <<rot-mat.png>>

%not sure which type frame/ point zyz/xyz etc...
quat=quaternion(angles,"euler","ZYZ","frame")
rotation=rotmat(quat,"frame")

%or inverse
correct= data * rotation
end