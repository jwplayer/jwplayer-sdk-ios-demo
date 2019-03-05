//
//  Dictionary+PrettyPrint.swift
//  JWStreamNAdTester
//
//  Created by Amitai Blickstein on 12/22/18.
//  Copyright © 2018 Amitai Blickstein. All rights reserved.
//

import Foundation

 /// Pretty print, in order if possible.
extension Dictionary where Key: Comparable {
    @discardableResult
    func prettyPrint(sorted sortResult: Bool) -> String {
        guard sortResult else { return prettyPrint() }
        
        var result = ""
        for (key, value) in self.sorted(by: {$0.0 < $1.0 }) {
            result += "\"\(key)\" :  \(value)\n"
        }
        return result
    }
}

extension Dictionary
{
    @discardableResult
    func prettyPrint() -> String {
        var result = ""
        for (key, value) in self {
            result += "\"\(key)\" :  \(value)\n"
        }
        return result
    }
}
