//
//  PrettyPrinter.swift
//  JWPlayer-Demo
//
//  Created by Amitai Blickstein on 7/5/18.
//  Copyright © 2018 Daniel Berger. All rights reserved.
//

import Foundation

class PrettyPrinter {
    static func print(json tryJSON: Any) -> String {
        var result = "\(tryJSON)"
        do {
            guard JSONSerialization.isValidJSONObject(tryJSON) else { return result }
            let data = try JSONSerialization.data(withJSONObject: tryJSON, options: .prettyPrinted)
            guard let string = String(data: data, encoding: .utf8) else { return result }
            result = string
        }
        catch {
            Swift.print("\nJSON printing error, falling back on `description` method\n")
        }
        
        return result
    }
}
