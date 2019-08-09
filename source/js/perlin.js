.import "generalUtils.js" as Utils
.import "simple3D.js" as Simple3D

/*
    Type definitions

    vector:         { x: float, y: float, z: float }

*/

function hash(vec) {
    return Utils.fract(Math.sin(Simple3D.vector3Dot(vec, { x: 127.1, y: 311.7, z: 321.4 })) * 43758.5453123)
}

function noise(pos) {
    var i = Simple3D.vector3Floor(pos)
    var f = Simple3D.vector3Fract(pos)

    f = Simple3D.vector3Mul(f, Simple3D.vector3Mul(f, Simple3D.vector3Sub({ x: 3.0, y: 3.0, z: 3.0 }, Simple3D.vector3MulScalar(f, 2.0))))

    var n = Utils.mix(
                Utils.mix(Utils.mix(hash( Simple3D.vector3Add(i, { x: 0.0, y: 0.0, z: 0.0 }) ), hash( Simple3D.vector3Add(i, { x: 1.0, y: 0.0, z: 0.0 }) ), f.x),
                          Utils.mix(hash( Simple3D.vector3Add(i, { x: 0.0, y: 1.0, z: 0.0 }) ), hash( Simple3D.vector3Add(i, { x: 1.0, y: 1.0, z: 0.0 }) ), f.x),
                          f.y),
                Utils.mix(Utils.mix(hash( Simple3D.vector3Add(i, { x: 0.0, y: 0.0, z: 1.0 }) ), hash( Simple3D.vector3Add(i, { x: 1.0, y: 0.0, z: 1.0 }) ), f.x),
                          Utils.mix(hash( Simple3D.vector3Add(i, { x: 0.0, y: 1.0, z: 1.0 }) ), hash( Simple3D.vector3Add(i, { x: 1.0, y: 1.0, z: 1.0 }) ), f.x),
                          f.y),
                f.z)

    return Utils.clippedValue((n - 0.49) * 2.05, -1.0, 1.0)
}
