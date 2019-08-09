.import "generalUtils.js" as Utils
.import "simple3D.js" as Simple3D

/*
    Type definitions

    vector:         { x: float, y: float, z: float }
    geoloc:         { latitude: float, longitude: float, altitude: float }

*/

var earthRadiusM = 6371000

function geolocToVector(reference, geoloc) {
    var vector = { x: 0, y: 0, z: -(earthRadiusM + Utils.feetToMeters(geoloc.altitude)) }

    // Transform geodesic to geocentric
    vector = Simple3D.rotatedVector3OnX(vector, geoloc.latitude)
    vector = Simple3D.rotatedVector3OnY(vector, geoloc.longitude)

    // Apply inverse angles of reference to geocentric coords
    vector = Simple3D.rotatedVector3OnY(vector, -reference.longitude)
    vector = Simple3D.rotatedVector3OnX(vector, -reference.latitude)
    vector = Simple3D.rotatedVector3OnX(vector, 90)

    // Adjust x and altitude
    vector.x = -vector.x
    vector.y = vector.y - (earthRadiusM + Utils.feetToMeters(reference.altitude))

    // Return topocentric coordinates
    return vector
}

function vectorToGeoloc(reference, vector) {
    var temp = { x: vector.x, y: vector.y, z: vector.z }
    var geoloc = { latitude: 0, longitude: 0, altitude: 0 }

    // Adjust x and altitude
    temp.y = (earthRadiusM + Utils.feetToMeters(reference.altitude)) + temp.y

    // Apply angles of reference to geocentric coords
    temp = Simple3D.rotatedVector3OnX(temp, 90)
    temp = Simple3D.rotatedVector3OnX(temp, reference.latitude)
    temp = Simple3D.rotatedVector3OnY(temp, reference.longitude)

    // Transform geocentric to geodesic
    geoloc.longitude = Simple3D.vectorYAngle(temp)
    temp = Simple3D.rotatedVector3OnY(temp, -geoloc.longitude)
    geoloc.latitude = Simple3D.vectorXAngle(temp)
    temp = Simple3D.rotatedVector3OnX(temp, -geoloc.latitude)
    geoloc.altitude = Utils.metersToFeet(Math.abs(temp.z) - earthRadiusM)

    // Return geodesic coordinates
    return geoloc
}

function drawGeoScene(context, width, height, camera, scene, referenceGeoloc) {
    for (var index = 0; index < scene.objects.length; index++) {
        var geoloc = scene.objects[index].geoloc
        var position = geolocToVector(referenceGeoloc, geoloc)
        var rotation = scene.objects[index].rotation !== null && typeof scene.objects[index].rotation !== "undefined" ? scene.objects[index].rotation : { x: 0, y: 0, z: 0 }
        Simple3D.drawMesh(context, width, height, camera, scene.objects[index].mesh, position, rotation, scene.objects[index].color, null)
    }
}

function geodesicTest() {
    var ref = { latitude: 10, longitude: 10, altitude: 0 }
    var geoloc = { latitude: 20, longitude: 15, altitude: 0 }
    var vector = geolocToVector(ref, geoloc)
    console.log(geoloc.latitude, geoloc.longitude, geoloc.altitude)
    console.log(vector.x, vector.y, vector.z)
    geoloc = vectorToGeoloc(ref, vector)
    console.log(geoloc.latitude, geoloc.longitude, geoloc.altitude)
}
