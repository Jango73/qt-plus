.import "generalUtils.js" as Utils

/*
    Type definitions

    vector:         { x: float, y: float, z: float }
    axis:           { front: vector, up: vector, right: vector }
    plane:          { normal: vector, distance: float }
    polygon:        [ vector, vector, vector, ... ]
    mesh:           [ polygon, polygon, polygon, ... ]
    sceneObject:    { name: string, color: string, mesh: mesh }
    scene:          { objects: [sceneObject, sceneObject, sceneObject, ...] }

    camera:         { position: vector,
                      rotation: vector,
                      zoom: float,
                      screenCenter: vector,
                      clipPlanes: [plane, plane, ...],
                      zoomForClipPlanes: float }
*/

//-------------------------------------------------------------------------------------------------
// Vector functions

function vector3Floor(vec) {
    return { x: Math.floor(vec.x), y: Math.floor(vec.y), z: Math.floor(vec.z) }
}

function vector3Fract(vec) {
    return { x: Utils.fract(vec.x), y: Utils.fract(vec.y), z: Utils.fract(vec.z) }
}

function vector3Length(vec) {
    var squaredLength = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z

    if (Utils.isNaN(squaredLength) === false && squaredLength !== 0.0)
        return Math.sqrt(squaredLength)

    return 0.0
}

function vector3Dot(vec1, vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z
}

function vector3Add(vec1, vec2) {
    return { x: vec1.x + vec2.x, y: vec1.y + vec2.y, z: vec1.z + vec2.z }
}

function vector3Sub(vec1, vec2) {
    return { x: vec1.x - vec2.x, y: vec1.y - vec2.y, z: vec1.z - vec2.z }
}

function vector3Mul(vec1, vec2) {
    return { x: vec1.x * vec2.x, y: vec1.y * vec2.y, z: vec1.z * vec2.z }
}

function vector3Div(vec1, vec2) {
    return { x: vec1.x / vec2.x, y: vec1.y / vec2.y, z: vec1.z / vec2.z }
}

function vector3MulScalar(vec, value) {
    return { x: vec.x * value, y: vec.y * value, z: vec.z * value }
}

function vector3DivScalar(vec, value) {
    return { x: vec.x / value, y: vec.y / value, z: vec.z / value }
}

function rotatedVector3OnX(vec, angle) {
    var angleRadians = Utils.degreesToRadians(angle)
    var newY = vec.y * Math.cos(angleRadians) + vec.z * -Math.sin(angleRadians)
    var newZ = vec.y * Math.sin(angleRadians) + vec.z * Math.cos(angleRadians)
    return { x: vec.x, y: newY, z: newZ }
}

function rotatedVector3OnY(vec, angle) {
    var angleRadians = Utils.degreesToRadians(angle)
    var newZ = vec.z * Math.cos(angleRadians) + vec.x * -Math.sin(angleRadians)
    var newX = vec.z * Math.sin(angleRadians) + vec.x * Math.cos(angleRadians)
    return { x: newX, y: vec.y, z: newZ }
}

function rotatedVector3OnZ(vec, angle) {
    var angleRadians = Utils.degreesToRadians(angle)
    var newX = vec.x * Math.cos(angleRadians) + vec.y * -Math.sin(angleRadians)
    var newY = vec.x * Math.sin(angleRadians) + vec.y * Math.cos(angleRadians)
    return { x: newX, y: newY, z: vec.z }
}

function rotatedVector(vec, rotation) {
    var result = { x: vec.x, y: vec.y, z: vec.z }
    result = rotatedVector3OnZ(result, rotation.z)
    result = rotatedVector3OnX(result, rotation.x)
    result = rotatedVector3OnY(result, rotation.y)
    return result
}

function vectorXAngle(vec) {
    if (vec.y === 0)
        return 0

    return Utils.radiansToDegrees(Math.atan2(vec.z, vec.y) - (Math.PI * 0.5))
}

function vectorYAngle(vec) {
    if (vec.z === 0) {

        if (vec.x === 0)
            return 0

        return Utils.radiansToDegrees(Math.atan2(vec.z, vec.x) + (Math.PI * 0.5))
    }

    return Utils.radiansToDegrees(Math.atan2(vec.x, vec.z))
}

function vectorZAngle(vec) {
    if (vec.x === 0)
        return 0

    return Utils.radiansToDegrees(Math.atan2(vec.y, vec.x))
}

function eulerAngles(vec) {
    var temp = { x: vec.x, y: vec.y, z: vec.z }

    var y = vectorYAngle(temp)
    temp = rotatedVector3OnY(temp, -y)
    var x = vectorXAngle(temp)
    // temp = rotatedVector3OnX(temp, -x)

    return { x: x, y: y, z: 0 }
}

function eulerAnglesWithFrontAndRight(front, right) {
    var temp1 = { x: front.x, y: front.y, z: front.z }
    var temp2 = { x: right.x, y: right.y, z: right.z }

    var y = vectorYAngle(temp1)
    temp1 = rotatedVector3OnY(temp1, -y)
    temp2 = rotatedVector3OnY(temp2, -y)
    var x = vectorXAngle(temp1)
    temp2 = rotatedVector3OnX(temp2, -x)
    var z = vectorZAngle(temp2)

    return { x: x, y: y, z: z }
}

function inverseEulerAngles(vec) {
    var result = eulerAngles(vec)
    return { x: -result.x, y: -result.y, z: -result.z }
}

//-------------------------------------------------------------------------------------------------
// Bezier functions

function vector3DInterpolate(vec1, vec2, t) {
    return vector3Add(vector3MulScalar(vec1, (1.0 - t)), vector3MulScalar(vec2, t))
}

function bezier(p0, p1, p2, p3, t) {
    var a = vector3DInterpolate(p0, p1, t);
    var b = vector3DInterpolate(p1, p2, t);
    var c = vector3DInterpolate(p2, p3, t);
    var d = vector3DInterpolate(a, b, t);
    var e = vector3DInterpolate(b, c, t);
    var pointOnCurve = vector3DInterpolate(d, e, t);

    return pointOnCurve;
}

//-------------------------------------------------------------------------------------------------
// Polygon functions

function translatePolygon(polygon, vector) {
    var result = []

    for (var vertex = 0; vertex < polygon.length; vertex++) {
        result.push(vector3Add(vector, polygon[vertex]))
    }

    return result
}

function rotatePolygonOnY(polygon, angle) {
    var result = []

    for (var vertex = 0; vertex < polygon.length; vertex++) {
        result.push(rotatedVector3OnY(polygon[vertex], angle))
    }

    return result
}

function transformPolygon(polygon, position, rotation) {
    var outPolygon = []

    for (var index = 0; index < polygon.length; index++) {
        var vertex = { x: polygon[index].x, y: polygon[index].y, z: polygon[index].z }

        if (rotation !== null) {
            if (rotation.z !== 0)
                vertex = rotatedVector3OnZ(vertex, rotation.z)

            if (rotation.x !== 0)
                vertex = rotatedVector3OnX(vertex, rotation.x)

            if (rotation.y !== 0)
                vertex = rotatedVector3OnY(vertex, rotation.y)
        }

        if (position !== null) {
            vertex = vector3Add(position, vertex)
        }

        outPolygon.push(vertex)
    }

    return outPolygon
}

function polygonAverageZ(polygon) {
    var average = 0

    if (polygon.length > 0) {
        for (var index = 0; index < polygon.length; index++) {
            average += polygon[index].z
        }

        average /= polygon.length
    }

    return average
}

function polygonDrawable(polygon, width, height) {
    if (polygon.length === 0)
        return false

    for (var index = 0; index < polygon.length; index++) {
        if (polygon[index].x < -(width * 11)) return false;
        if (polygon[index].x >  (width * 10)) return false;

        if (polygon[index].y < -(height * 11)) return false;
        if (polygon[index].y >  (height * 10)) return false;

        if (polygon[index].z < 0) return false;
    }

    return true
}

//-------------------------------------------------------------------------------------------------
// Projection functions

function worldToPixels(camera, vector) {
    var vertex = { x: vector.x, y: vector.y, z: vector.z }
    var screenCenter = { x: 50, y: 50 }
    var pixelRange = 100

    if (camera.screenCenter !== null && typeof camera.screenCenter !== "undefined") {
        screenCenter = { x: camera.screenCenter.x, y: camera.screenCenter.y }
        pixelRange = Math.min(screenCenter.x, screenCenter.y) * 2
    }

    // Transform to camera space
    if (camera.position !== null && typeof camera.position !== "undefined") {
        vertex = vector3Sub(vertex, camera.position)
    }

    if (camera.rotation !== null && typeof camera.rotation !== "undefined") {
        if (camera.rotation.y !== 0)
            vertex = rotatedVector3OnY(vertex, -camera.rotation.y)
        if (camera.rotation.x !== 0)
            vertex = rotatedVector3OnX(vertex, -camera.rotation.x)
        if (camera.rotation.z !== 0)
            vertex = rotatedVector3OnZ(vertex, -camera.rotation.z)
    }

    // Project
    vertex.x = (vertex.x / vertex.z)
    vertex.y = (vertex.y / vertex.z)

    if (camera.zoom !== null) {
        vertex.x *= camera.zoom
        vertex.y *= camera.zoom
    }

    // Transform to screen space
    vertex.x = screenCenter.x + vertex.x * pixelRange
    vertex.y = screenCenter.y - vertex.y * pixelRange

    return vertex
}

function worldToPixelsSize(camera, vec, size) {
    var vec1 = { x: -size * 0.5, y: -size * 0.5, z: -size * 0.5 }
    var vec2 = { x:  size * 0.5, y:  size * 0.5, z:  size * 0.5 }

    vec1 = worldToPixels(camera, vec1)
    vec2 = worldToPixels(camera, vec2)

    var diff = vector3Sub(vec2, vec1)

    diff.x = Math.abs(diff.x)
    diff.y = Math.abs(diff.y)

    return (diff.x + diff.y) / 2
}

function polygonToPixels(camera, polygon, close) {
    var result = []
    var halfFOV = Utils.degreesToRadians(45 / (camera.zoom !== null ? camera.zoom : 1.0))
    var index
    var screenCenter = { x: 50, y: 50 }
    var pixelRange = 100

    if (camera.screenCenter !== null && typeof camera.screenCenter !== "undefined") {
        screenCenter = { x: camera.screenCenter.x, y: camera.screenCenter.y }
        pixelRange = Math.min(screenCenter.x, screenCenter.y) * 2
    }

    if (camera.zoomForClipPlanes === null || camera.zoomForClipPlanes !== camera.zoom) {
        var sin = Math.sin(halfFOV)
        var cos = Math.cos(halfFOV)

        camera.clipPlanes = []
        camera.clipPlanes.push( { normal: { x: -cos, y:    0, z: sin }, distance: 0.0 } )
        camera.clipPlanes.push( { normal: { x:  cos, y:    0, z: sin }, distance: 0.0 } )
        camera.clipPlanes.push( { normal: { x:    0, y: -cos, z: sin }, distance: 0.0 } )
        camera.clipPlanes.push( { normal: { x:    0, y:  cos, z: sin }, distance: 0.0 } )
        camera.clipPlanes.push( { normal: { x:    0, y:    0, z:   1 }, distance: 1.0 } )

        camera.zoomForClipPlanes = camera.zoom
    }

    for (index = 0; index < polygon.length; index++) {
        var vertex = { x: polygon[index].x, y: polygon[index].y, z: polygon[index].z }

        // Transform to camera space
        vertex = vector3Sub(vertex, camera.position)

        if (camera.rotation !== null && typeof camera.rotation !== "undefined") {
            if (camera.rotation.y !== 0)
                vertex = rotatedVector3OnY(vertex, -camera.rotation.y)
            if (camera.rotation.x !== 0)
                vertex = rotatedVector3OnX(vertex, -camera.rotation.x)
            if (camera.rotation.z !== 0)
                vertex = rotatedVector3OnZ(vertex, -camera.rotation.z)
        }

        // Add this vertex to result
        result.push(vertex)
    }

    // Clip polygon to camera frustum
    result = clipPolygonToPlanes(result, camera.clipPlanes, close)

    // Finalize polygon transforms
    for (index = 0; index < result.length; index++) {
        // Project
        result[index].x = (result[index].x / result[index].z)
        result[index].y = (result[index].y / result[index].z)

        if (camera.zoom !== null) {
            result[index].x *= camera.zoom
            result[index].y *= camera.zoom
        }

        // Transform to screen space
        result[index].x = screenCenter.x + result[index].x * pixelRange
        result[index].y = screenCenter.y - result[index].y * pixelRange
    }

    return result
}

//-------------------------------------------------------------------------------------------------
// Clipping functions

function clipPolygonToPlanes(polygon, planes, close) {
    var outPolygon = polygon

    for (var index = 0; index < planes.length; index++) {
        outPolygon = clipPolygon(outPolygon, planes[index], close)
    }

    return outPolygon
}

function clipPolygon(polygon, plane, close) {
    var outPolygon = []
    var inIndex = 0
    var outIndex = 0
    var count = 0

    if (polygon.length === 0)
        return outPolygon

    var curDot = vector3Dot(polygon[0], plane.normal)
    var curIn = curDot >= plane.distance

    for (var index = 0; index < polygon.length; index++) {
        var nextIndex = (index + 1) % polygon.length;

        // Keep the current vertex if it's inside the plane
        if (curIn) {
            outPolygon.push( { x: polygon[inIndex].x, y: polygon[inIndex].y, z: polygon[inIndex].z } )
            count++;
        }

        if (close || nextIndex > 0) {
            // Compute dot product of next vertex
            var nextDot = vector3Dot(polygon[nextIndex], plane.normal)
            var nextIn = nextDot >= plane.distance

            // Add a clipped vertex if one end of the current edge is
            // inside the plane and the other is outside
            if (curIn !== nextIn) {
                var nsc = nextDot - curDot;
                var scale = 0

                if (nsc !== 0)
                    scale = (plane.distance - curDot) / nsc;

                var newX = polygon[inIndex].x + ((polygon[nextIndex].x - polygon[inIndex].x) * scale);
                var newY = polygon[inIndex].y + ((polygon[nextIndex].y - polygon[inIndex].y) * scale);
                var newZ = polygon[inIndex].z + ((polygon[nextIndex].z - polygon[inIndex].z) * scale);

                outPolygon.push( { x: newX, y: newY, z: newZ } )
                count++;
            }
        }

        curDot = nextDot;
        curIn  = nextIn;
        inIndex++;
    }

    return outPolygon
}

function drawTransformedPolygon(context, polygon, close, fillColor, strokeColor, thickness) {
    if (polygon.length > 0) {
        if (fillColor !== null)
            context.fillStyle = fillColor

        if (strokeColor !== null)
            context.strokeStyle = strokeColor

        if (thickness !== null)
            context.lineWidth = thickness
        else
            context.lineWidth = 1

        context.beginPath()
        context.moveTo(polygon[0].x, polygon[0].y)

        for (var vertex = 1; vertex < polygon.length; vertex++) {
            context.lineTo(polygon[vertex].x, polygon[vertex].y)
        }

        if (close)
            context.closePath()

        if (fillColor !== null)
            context.fill()

        if (strokeColor !== null)
            context.stroke()
    }
}

//-------------------------------------------------------------------------------------------------
// Mesh rendering functions

function drawPolygon(context, width, height, camera, polygon, position, rotation, fillColor, strokeColor, thickness) {
    var polygonToDraw = transformPolygon(polygon, position, rotation)

    polygonToDraw = polygonToPixels(camera, polygonToDraw, true)

    if (polygonDrawable(polygonToDraw, width, height)) {
        drawTransformedPolygon(context, polygonToDraw, true, fillColor, strokeColor, thickness)
    }
}

function drawPolyline(context, width, height, camera, polygon, close, position, rotation, fillColor, strokeColor, thickness) {
    var polygonToDraw = transformPolygon(polygon, position, rotation)

    polygonToDraw = polygonToPixels(camera, polygonToDraw, false)

    if (polygonDrawable(polygonToDraw, width, height)) {
        drawTransformedPolygon(context, polygonToDraw, close, fillColor, strokeColor, thickness)
    }
}

function drawMesh(context, width, height, camera, mesh, position, rotation, fillColor, strokeColor) {
    for (var index = 0; index < mesh.length; index++) {
        drawPolygon(context, width, height, camera, mesh[index], position, rotation, fillColor, strokeColor)
    }
}

//-------------------------------------------------------------------------------------------------
// Scenery rendering functions

function drawScene(context, width, height, camera, scene, position, rotation) {
    for (var index = 0; index < scene.objects.length; index++) {
        drawMesh(context, width, height, camera, scene.objects[index].mesh, position, rotation, scene.objects[index].color, null)
    }
}

//-------------------------------------------------------------------------------------------------
// Camera functions

function lookAt(from, to) {
    var difference = vector3Sub(to, from)
    return eulerAngles(difference)
}

function orbit(from, rotation, distance) {
    var position = { x: 0, y: 0, z: -distance }

    position = rotatedVector3OnX(position, rotation.x)
    position = rotatedVector3OnY(position, rotation.y)

    if (from !== null)
        position = vector3Add(from, position)

    return position
}

function orbitRight(from, rotation, distance) {
    var position = { x: -distance, y: 0, z: 0 }

    position = rotatedVector3OnX(position, rotation.x)
    position = rotatedVector3OnY(position, rotation.y)

    if (from !== null)
        position = vector3Add(from, position)

    return position
}
